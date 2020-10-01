#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__

#include <utility> // for std::pair
#include <vector>
#include <string>
#include <list>
#include <stdexcept>
#include <iostream>
#include "../Exceptions/hash_exception.h"


// helper functions to find a prime size
bool isPrime(size_t);
size_t getClosestBigEnoughPrime(size_t);

typedef size_t(*HashFunc)(const std::string&, size_t);
size_t defaultHashFunc(const std::string&, size_t);


template<typename T>
class HashMap
{ 	
	template<typename U>
	friend std::ostream& operator<<(std::ostream&, const HashMap<U>&);

public:
	// user must make sure his hashFunc is valid
        explicit HashMap(size_t hashSize = hashTableSize, HashFunc hashFunc = defaultHashFunc);

	void insert(const std::string&, const T&);
        void remove(const std::string&);

	// throw exception if key for read/write does not exist
	const T& operator[](const std::string&) const;

        T& operator[](const std::string&);

	void rehash(size_t);
	void setHashFunc(HashFunc);
	void setHashSize(size_t);

	size_t getHashSize() const;
	size_t getNumOfKeyValuePairs() const;
        size_t getNumOfBucketsInUse() const;
	float getUtilization() const;
        T getValueByKey(const std::string&) const;

        // returns all keys in hashMap
        std::vector<std::string> keys() const;

private:
	typedef std::pair<std::string, T> keyValuePair;
	typedef std::list<keyValuePair> Bucket;
	typedef std::vector<Bucket> HashTable;
	typedef typename std::list<keyValuePair>::iterator bucketIterator;
	typedef typename std::list<keyValuePair>::const_iterator constBucketIterator;

	HashTable m_hashTable;
	size_t m_hashSize;
	HashFunc m_hashFunc;

	//should be prime so keys should be uniformly distributed in hash table
	static const size_t hashTableSize = 71;
    	
	size_t m_numOfkeyValuePairs;
        size_t m_numOfBucketsInUse;

	size_t getMappedKey(const std::string&) const;
	bool isBucketEmpty(size_t) const;
	void updateNumOfBucketsInUse();
	
};


template<typename T>
inline HashMap<T>::HashMap(size_t hashSize, HashFunc hashFunc):m_hashTable(HashTable(getClosestBigEnoughPrime(hashSize))),m_hashSize(getClosestBigEnoughPrime(hashSize)),m_hashFunc(hashFunc),m_numOfkeyValuePairs(0),m_numOfBucketsInUse(0)
{}

template<typename T>
inline void HashMap<T>::insert(const std::string &key, const T &value)
{
	bool keyExistsInTable = false;
	// get the bucket where this key is mapped to
        size_t bucket = getMappedKey(key);
	
	for (bucketIterator it = m_hashTable[bucket].begin(); it != m_hashTable[bucket].end(); ++it)
	{
		// check if key alreay exists in hash table
                if (it->first == key)
		{
			keyExistsInTable = true;
			it->second = value;
			break;
		}
	}
	
        if (!keyExistsInTable) 
	{
	        // key does not exist already in table so we add it to the bucket it is mapped to
                std::pair <std::string, T> pair(key, value); 

		// bucket was not in use till now
		m_numOfBucketsInUse += isBucketEmpty(bucket);

                m_hashTable[bucket].push_back(pair);
                m_numOfkeyValuePairs++;
	
        }
}

template<typename T>
inline void HashMap<T>::remove(const std::string &key)
{
	size_t bucket = getMappedKey(key);
	
        std::pair <std::string, T> pair(key, getValueByKey(key)); 
	
	// case where key doesn't exist in hash table
        if (getValueByKey(key) == T())
	        return;

        m_hashTable[bucket].remove(pair);
        m_numOfkeyValuePairs--;
	
	// bucket is not in use anymore
	m_numOfBucketsInUse -= isBucketEmpty(bucket);
}

template<typename T>
inline const T& HashMap<T>::operator[](const std::string &key) const
{
	size_t bucket = getMappedKey(key);
    	
        for (constBucketIterator it = m_hashTable[bucket].begin(); it != m_hashTable[bucket].end(); ++it) 
	{
                if (it->first == key) 
		{
                        return it->second;
                }
        }

	throw HashException("key error");
}

template<typename T>
inline T& HashMap<T>::operator[](const std::string &key)
{
	size_t bucket = getMappedKey(key);
    	
        for (bucketIterator it = m_hashTable[bucket].begin(); it != m_hashTable[bucket].end(); ++it) 
	{
                if (it->first == key) 
		{
                        return it->second;
                }
        }

	throw HashException("key error");
}

template<typename T>
inline void HashMap<T>::rehash(size_t newHashSize) 
{
	newHashSize = getClosestBigEnoughPrime(newHashSize);

	// no need to rehash if new size is like current size
	if (m_hashSize != newHashSize)
	{
		// rearrange all keys in the new hash table with the new size
	        HashMap<T> newHashMap(newHashSize);

	        for (size_t i = 0; i < m_hashSize; i++) 
	        {
		        for (constBucketIterator it = m_hashTable[i].begin(); it != m_hashTable[i].end(); ++it) 
			{
		                newHashMap.insert(it->first, it->second);
			}

	        }
	        m_hashTable = newHashMap.m_hashTable;
	        m_hashSize = newHashSize;
		// number of buckets in use may have changed
		updateNumOfBucketsInUse();
	}
}

template<typename T>
inline void HashMap<T>::setHashFunc(HashFunc newHashFunc) 
{
	m_hashFunc = newHashFunc;
	// must rearrange all keys
        rehash(m_hashSize);
}

template<typename T>
inline void HashMap<T>::setHashSize(size_t newHashSize) 
{
	// must rearrange all keys
        rehash(newHashSize);
}

template<typename T>
inline T HashMap<T>::getValueByKey(const std::string &key) const
{
	size_t bucket = getMappedKey(key);

        for (constBucketIterator it = m_hashTable[bucket].begin(); it != m_hashTable[bucket].end(); ++it) 
	{
                if (it->first == key) 
		{
                        return it->second;
		}
        }
    
        return T();
}

template<typename T>
inline std::vector<std::string> HashMap<T>::keys() const
{
        std::vector<std::string> hashedKeys;

        for (size_t i = 0; i < m_hashSize; i++) 
	{
                for (constBucketIterator it = m_hashTable[i].begin(); it != m_hashTable[i].end(); ++it) 
		{
		        hashedKeys.push_back(it->first);
		}
        }
        
        return hashedKeys;
}

template<typename T>
inline size_t HashMap<T>::getHashSize() const
{
	return m_hashSize;
}

template<typename T>
inline size_t HashMap<T>::getNumOfKeyValuePairs() const 
{
	return m_numOfkeyValuePairs;
}

template<typename T>
inline size_t HashMap<T>::getNumOfBucketsInUse() const 
{
	return m_numOfBucketsInUse;
}

template<typename T>
inline size_t HashMap<T>::getMappedKey(const std::string &key) const
{
	return m_hashFunc(key, m_hashSize);
}

template<typename T>
inline float HashMap<T>::getUtilization() const 
{
	// avoid zero-division
	return getHashSize() ? (float)getNumOfBucketsInUse() / (float)getHashSize() : 0;
}

template<typename T>
inline bool HashMap<T>::isBucketEmpty(size_t bucket) const
{
	return m_hashTable[bucket].size() == 0;
}

template<typename T>
inline void  HashMap<T>::updateNumOfBucketsInUse()
{
	m_numOfBucketsInUse = 0;
        for (size_t i = 0; i < m_hashSize; ++i) 
	{
                if (m_hashTable[i].size()) 
		{
                        m_numOfBucketsInUse++;
                }
        }
}

template<typename U>
inline std::ostream &operator<<(std::ostream &os, const HashMap<U> &hashMap) 
{
        for (size_t i = 0; i < hashMap.m_hashSize; i++) 
	{
	        typename HashMap<U>::constBucketIterator it;
                for (it = hashMap.m_hashTable[i].begin(); it != hashMap.m_hashTable[i].end(); ++it) 
		{
                        std::cout << "myHashMap[" << it->first << "] = " << it->second << std::endl;
                }
        }

        return os;
}

#endif /*__HASH_MAP_H__*/

#ifndef __IPARAMS_H__
#define __IPARAMS_H__

#include <vector>
#include <string>


class IParams
{
public:
        virtual ~IParams();

        virtual void buildParams(const std::vector<std::string>&) = 0;

        std::vector<std::string> m_params;

private:
        virtual bool isNumParamsValid(size_t) const = 0;

};

inline IParams::~IParams()
{
}

#endif /* __IPARAMS_H__*/

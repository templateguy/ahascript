//
//  Delimiters.hpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#pragma once


#include <string>
#include <vector>
#include <algorithm>


namespace aha
{
    template <typename T = char>
    class Delimiters
    {
    public:
        Delimiters()
        {
            static const std::string defaultDelimiters_{" ,<.>/?;:'\"[{]}\\|`~!@#$%^&*()-=+\t\r\n\0"};
            createDelimiters_(defaultDelimiters_);
        }
        
        Delimiters(const std::string& str)
        {
            createDelimiters_(str);
        }
        
        inline bool exists(T delimiter) const
        {
            auto i(std::find(delimiters_.begin(), delimiters_.end(), delimiter));
            return i != delimiters_.end();
        }
        
    protected:
        void createDelimiters_(const std::string& str)
        {
            for(auto ch : str)
            {
                delimiters_.emplace_back(ch);
            }
        }
        
        std::vector <T> delimiters_;
    };
}

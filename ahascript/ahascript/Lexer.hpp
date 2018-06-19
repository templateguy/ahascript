//
//  Lexer.hpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#pragma once


#include <iostream>
#include "Delimiters.hpp"


namespace aha
{
    class Lexer
    {
    public:
        Lexer(const std::string& input)
        {
            lex_(input);
        }
        
        template <typename T>
        Lexer(const std::string& input, const Delimiters <T>& delimiters)
        {
            lex_(input, delimiters);
        }
        
        template <typename T>
        Lexer(const std::string& input, const Delimiters <T>& delimiters, const Delimiters <T>& skipCharacters)
        {
            lex_(input, delimiters, skipCharacters);
        }
        
        inline const std::vector <std::string>& getTokens() const
        {
            return tokens_;
        }
        
        void print() const
        {
            for(const auto& token : tokens_)
            {
                std::cout << token << std::endl;
            }
        }
        
    protected:
        inline void lex_(const std::string& input)
        {
            static Delimiters <> delimiters;
            lex_(input, delimiters);
        }
        
        template <typename T>
        inline void lex_(const std::string& input, const Delimiters <T>& delimiters)
        {
            static Delimiters <> skipCharacters(" \t\r\n");
            lex_(input, delimiters, skipCharacters);
        }
        
        template <typename T>
        void lex_(const std::string& input, const Delimiters <T>& delimiters, const Delimiters <T>& skipCharacters)
        {
            std::string token;
            for(auto ch : input)
            {
                if(delimiters.exists(ch))
                {
                    if(token.size())
                    {
                        tokens_.emplace_back(token);
                    }
                    if(!skipCharacters.exists(ch))
                    {
                        token = ch;
                        tokens_.emplace_back(token);
                    }
                    token.clear();
                    continue;
                }
                token += ch;
            }
        }
        
        std::vector <std::string> tokens_;
    };
}

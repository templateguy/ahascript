//
//  Preprocessor.hpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#pragma once


#include <string>
#include <vector>
#include <fstream>
#include <sstream>


namespace aha::pp::private_
{
    struct Config__
    {
        const std::vector <std::string> directives =
        {
            "#pragma",
            "#include",
            "#define",
            "#undef",
            "#if",
            "#ifdef",
            "#ifndef",
            "#elif",
            "#else",
            "#endif",
            "#error",
            "#warning",
            "#line"
        };
        
        const std::vector <std::string> commands =
        {
            "once",
            "defined",
            "pack"
        };
        
        const std::vector <std::string> punctuators =
        {
            " ",
            ",",
            "<",
            ">",
            "(",
            ")",
            "\\",
            "\t",
            "\n"
        };
        
        const std::vector <std::string> operators =
        {
            "&&",
            "||",
            "!"
        };
        
        static Config__& getInstance()
        {
            static Config__ instance;
            return instance;
        }
        
        Config__(const Config__&) = delete;
        Config__(Config__&&) = delete;
        const Config__& operator =(const Config__&) = delete;
        Config__& operator =(Config__&&) = delete;
        
    private:
        Config__() = default;
    };
    
#define Config_ Config__::getInstance()
    
    class Token_ final
    {
    public:
        enum class Type : uint8_t
        {
            None,
            Directive,
            Command,
            Parameter,
            Punctuator,
            Operator,
            Unknown
        };
        
        Token_(const std::string& value) noexcept : value_{value}
        {
            identifyType_();
        }
        
        inline Type getType() const noexcept
        {
            return type_;
        }
        
        inline const std::string& getValue() const noexcept
        {
            return value_;
        }
        
        inline void print() const noexcept
        {
            std::string type;
            if(type_ == Type::None)
                type = "None";
            else if(type_ == Type::Directive)
                type = "Directive";
            else if(type_ == Type::Command)
                type = "Command";
            else if(type_ == Type::Punctuator)
                type = "Punctuator";
            else if(type_ == Type::Operator)
                type = "Operator";
            else
                type = "Unknown";
            std::cout << "Token Type: " << type << ", Value: " << value_ << std::endl;
        }
        
    private:
        void identifyType_() noexcept
        {
            if(std::end(Config_.directives) != std::find(std::begin(Config_.directives), std::end(Config_.directives), value_.c_str()))
            {
                type_ = Type::Directive;
            }
            else if(std::end(Config_.commands) != std::find(std::begin(Config_.commands), std::end(Config_.commands), value_.c_str()))
            {
                type_ = Type::Command;
            }
            else if(std::end(Config_.punctuators) != std::find(std::begin(Config_.punctuators), std::end(Config_.punctuators), value_.c_str()))
            {
                type_ = Type::Punctuator;
            }
            else if(std::end(Config_.operators) != std::find(std::begin(Config_.operators), std::end(Config_.operators), value_.c_str()))
            {
                type_ = Type::Operator;
            }
        }
        
        Type type_{Type::None};
        const std::string value_;
    };
    
    class Delimiters_ final
    {
    public:
        Delimiters_()
        {
            static const std::string defaultDelimiters_{" ,<.>/?;:'\"[{]}\\`~@$%^*()-=+\t\r\n\0"};
            createDelimiters_(defaultDelimiters_);
        }
        
        Delimiters_(const std::string& str)
        {
            createDelimiters_(str);
        }
        
        inline bool exists(char delimiter) const
        {
            auto i(std::find(delimiters_.begin(), delimiters_.end(), delimiter));
            return i != delimiters_.end();
        }
        
    private:
        void createDelimiters_(const std::string& str) noexcept
        {
            for(auto ch : str)
            {
                delimiters_.emplace_back(ch);
            }
        }
        
        std::vector <char> delimiters_;
    };
    
    class Lexer_ final
    {
    public:
        Lexer_(const std::string& input)
        {
            lex_(input);
        }
        
        inline const std::vector <Token_>& getTokens() const noexcept
        {
            return tokens_;
        }
        
    private:
        void lex_(const std::string& input, const Delimiters_& delimiters = Delimiters_())
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
                    token = ch;
                    tokens_.emplace_back(token);
                    token.clear();
                    continue;
                }
                token += ch;
            }
        }
        
        std::vector <Token_> tokens_;
    };
}

namespace aha::pp
{
    class Preprocessor final
    {
    public:
        Preprocessor(const std::string& fileName)
        {
            std::ifstream file;
            file.open(fileName.c_str());
            std::stringstream fileStream;
            fileStream << file.rdbuf();
            file.close();
            input_ = fileStream.str();
        }
        
        const auto& operator ()()
        {
            private_::Lexer_ lexer(input_);
            const auto& tokens(lexer.getTokens());
            for(const auto& token : tokens)
            {
                token.print();
            }
            return preprocessed_;
        }
        
    private:
        void pragma_()
        {
            
        }
        
        void include_()
        {
            
        }
        
        void define_()
        {
            
        }
        
        std::string input_;
        std::string preprocessed_;
        std::vector <std::string> tokens_;
    };
}

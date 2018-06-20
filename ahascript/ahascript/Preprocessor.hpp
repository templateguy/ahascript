//
//  Preprocessor.hpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#pragma once


#include <fstream>
#include <sstream>
#include "Lexer.hpp"
#include "PreprocessorToken.hpp"


namespace aha
{
    class Preprocessor
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
            Lexer lexer(input_);
            const auto& tokens(lexer.getTokens());
            interpret_(tokens);
            return preprocessed_;
        }
        
    protected:
        void interpret_(const std::vector <std::string>& tokens)
        {
            for(const auto& strToken : tokens)
            {
                identifyToken_(strToken);
                auto token(identifyToken_(strToken));
                buildCommand_(token);
            }
        }
        
        PreprocessorToken identifyToken_(const std::string& token)
        {
            if(token == "#")        return PreprocessorToken::Hash;
            if(token == "include")  return PreprocessorToken::Include;
            if(token == "define")   return PreprocessorToken::Define;
            if(token == "pragma")   return PreprocessorToken::Pragma;
            if(token == "if")       return PreprocessorToken::If;
            if(token == "ifdef")    return PreprocessorToken::IfDef;
            if(token == "ifndef")   return PreprocessorToken::IfNDef;
            if(token == "defined")  return PreprocessorToken::Defined;
            if(token == "elif")     return PreprocessorToken::ElIf;
            if(token == "else")     return PreprocessorToken::Else;
            if(token == "<")        return PreprocessorToken::LeftAngleBracket;
            if(token == ">")        return PreprocessorToken::RightAngleBracket;
            if(token == "(")        return PreprocessorToken::LeftParentheses;
            if(token == ")")        return PreprocessorToken::RightParentheses;
            if(token == "\"")       return PreprocessorToken::DoubleQuote;
            if(token == "&")        return PreprocessorToken::And;
            if(token == "|")        return PreprocessorToken::Or;
            if(token == "!")        return PreprocessorToken::Not;
            return PreprocessorToken::Unknown;
        }
        
        void buildCommand_(PreprocessorToken token)
        {
            switch(token)
            {
                case PreprocessorToken::Hash:
                    
                    break;
                    
                case PreprocessorToken::Include:
                    
                    break;
                
                case PreprocessorToken::Define:
                    
                    break;
                
                case PreprocessorToken::Pragma:
                    
                    break;
                    
                case PreprocessorToken::If:
                    
                    break;
                    
                case PreprocessorToken::IfDef:
                    
                    break;
                    
                case PreprocessorToken::IfNDef:
                    
                    break;
                    
                case PreprocessorToken::Defined:
                    
                    break;
                    
                case PreprocessorToken::ElIf:
                    
                    break;
                    
                case PreprocessorToken::Else:
                    
                    break;
                    
                case PreprocessorToken::LeftAngleBracket:
                    
                    break;
                    
                case PreprocessorToken::RightAngleBracket:
                    
                    break;
                    
                case PreprocessorToken::LeftParentheses:
                    
                    break;
                    
                case PreprocessorToken::RightParentheses:
                    
                    break;
                    
                case PreprocessorToken::DoubleQuote:
                    
                    break;
                   
                case PreprocessorToken::Unknown:
                    
                    break;
                    
                default:
                    break;
            }
        }
        
        std::string input_;
        std::string preprocessed_;
        std::vector <std::string> tokens_;
    };
}

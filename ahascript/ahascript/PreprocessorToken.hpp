//
//  PreprocessorToken.hpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#pragma once


namespace aha
{
    enum class PreprocessorToken
    {
        Hash,
        Include,
        Define,
        Pragma,
        If,
        IfDef,
        IfNDef,
        Defined,
        ElIf,
        Else,
        LeftAngleBracket,
        RightAngleBracket,
        LeftParentheses,
        RightParentheses,
        DoubleQuote,
        And,
        Or,
        Not,
        Unknown
    };
}

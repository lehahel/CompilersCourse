project(ParserExampleWithAst)
set(
    HEADERS
    driver.hh
    parser.hh
)

BISON_TARGET(
    MyParserWithAst
    parser.y
    ${ParserExampleWithAst_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${ParserExampleWithAst_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScannerWithAst
    scanner.l
    ${ParserExampleWithAst_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScannerWithAst MyParserWithAst)

add_executable(
    ParserExampleWithAst
    main.cpp
    driver.cpp

    ${BISON_MyParserWithAst_OUTPUTS}
    ${FLEX_MyScannerWithAst_OUTPUTS}
    
    assignments/Assignment.cpp
    assignments/AssignmentList.cpp

    expression/BinaryOpExpression.cpp
    expression/UnaryOpExpression.cpp

    expression/IntExpression.cpp
    expression/DoubleExpression.cpp
    expression/StringExpression.cpp
    expression/BoolExpression.cpp

    statement/ExprStatement.cpp
    statement/StatementList.cpp
    statement/AssStatement.cpp

    lvalue/IdentLvalue.cpp
    
    visitor/PrintVisitor.cpp
    
    MainClass.cpp
    
    type/Type.cpp
    type/Int.hpp
    type/Double.hpp
    type/Bool.hpp
    type/String.hpp
    
    Program.cpp
)

target_include_directories(
    ParserExampleWithAst PRIVATE ${ParserExampleWithAst_SOURCE_DIR}
)




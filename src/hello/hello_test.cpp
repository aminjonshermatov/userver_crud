#include "hello.hpp"

#include "userver/utest/utest.hpp"

UTEST(SayHelloTo, Basic) {
  EXPECT_EQ(userver_crud::SayHelloTo("Developer"), "Hello, Developer!\n");
  EXPECT_EQ(userver_crud::SayHelloTo({}), "Hello, unknown user!\n");
}

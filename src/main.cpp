#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/utils/daemon_run.hpp>
#include <userver/clients/http/component.hpp>
#include <userver/testsuite/testsuite_support.hpp>
#include <userver/server/handlers/tests_control.hpp>


#include "hello/hello.hpp"
#include "crud/crud.hpp"

int main(int argc, char *argv[]) {
  auto component_list = userver::components::MinimalServerComponentList()
                            .Append<userver::server::handlers::Ping>()
                            .Append<userver::components::TestsuiteSupport>()
                            .Append<userver::components::HttpClient>()
                            .Append<userver::server::handlers::TestsControl>();

  userver_crud::AppendHello(component_list);
  userver_crud::AppendCrud(component_list);

  return userver::utils::DaemonMain(argc, argv, component_list);
}

#include "crud.hpp"

#include "userver/server/handlers/http_handler_json_base.hpp"

#include "userver/formats/json.hpp"

namespace userver_crud {

namespace {

class CrudService final : public userver::server::handlers::HttpHandlerJsonBase {
 public:
  static constexpr std::string_view kName = "handler-crud";

  CrudService(const userver::components::ComponentConfig &,
              const userver::components::ComponentContext &);

  userver::formats::json::Value HandleRequestJsonThrow(
      const userver::server::http::HttpRequest &,
      const userver::formats::json::Value &,
      userver::server::request::RequestContext &) const override;
};


userver_crud::CrudService::CrudService(
    const userver::components::ComponentConfig &component_config,
    const userver::components::ComponentContext &component_context)
    : HttpHandlerJsonBase(component_config, component_context) { }

userver::formats::json::Value userver_crud::CrudService::HandleRequestJsonThrow(
    const userver::server::http::HttpRequest &request,
    const userver::formats::json::Value &json,
    userver::server::request::RequestContext &request_context) const {
  userver::formats::json::ValueBuilder result;

  for (size_t i = 0u; i < request.PathArgCount(); ++i) {
    result["path_var"].PushBack(request.GetPathArg(i));
  }

  result["json"] = json;

  request.SetResponseStatus(userver::server::http::HttpStatus::kOk);
  return result.ExtractValue();
}

}  // namespace

void AppendCrud(userver::components::ComponentList &component_list) {
  component_list.Append<CrudService>();
}

}  // namespace userver_crud

#ifndef HTTP_REQUEST_HEADERS_HPP
#define HTTP_REQUEST_HEADERS_HPP

#include <unordered_map>
#include <variant>
#include <optional>
#include "http_connection_socket.hpp"

class HTTPRequestHeaders
{
private:
    std::string m_request{};
    std::string m_request_method{};
    std::string m_request_target{};
    std::string m_protocol_vers{};
    std::unordered_map<std::string, std::string> m_headers{};

    HTTPRequestHeaders(std::string request);
    void parse_request_line();
    void parse_headers();

public:
    // Only mechanism to create HTTPRequestHeaders obj from anywhere
    static std::optional<HTTPRequestHeaders> from_raw(std::string raw); 

    const std::string& get_request_method() const { return m_request_method; }
    const std::string& get_request_target() const { return m_request_target; }
    const std::string& get_protocol_vers() const { return m_protocol_vers; }
};

#endif
/* Copyright 2015 Realm Inc - All Rights Reserved
 * Proprietary and Confidential
 */
 
#include <realm.hpp>
#include <realm/lang_bind_helper.hpp>
#include "error_handling.hpp"
#include "realm_export_decls.hpp"
#include "object-store/src/shared_realm.hpp"
#include "object-store/src/schema.hpp"

using namespace realm;

extern "C" {

REALM_EXPORT std::vector<ObjectSchema>* schema_initializer_create()
{
    return handle_errors([&]() {
        return new std::vector<ObjectSchema>();
    });
}

REALM_EXPORT void schema_initializer_destroy(std::vector<ObjectSchema>* schema_initializer)
{
    handle_errors([&]() {
        delete schema_initializer;
    });
}

REALM_EXPORT void schema_initializer_add_object_schema(std::vector<ObjectSchema>* schema_initializer, ObjectSchema* object_schema)
{
    handle_errors([&]() {
        schema_initializer->push_back(std::move(*object_schema));
    });
}

REALM_EXPORT Schema* schema_create(std::vector<ObjectSchema>* object_schemas, size_t len)
{
    return handle_errors([&]() {
        return new Schema(*object_schemas);
    });
}

}   // extern "C"

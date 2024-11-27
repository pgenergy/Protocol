# Energyleaf Proto - Rust

Contains the protobuf files to interact with the energyleaf backend.


## Installation

Install energyleaf-proto

```bash
  cargo add energyleaf-proto
```
    
## Protocol

```proto
syntax = "proto3";

package energyleaf;

enum SensorType {
  ANALOG_ELECTRICITY = 0;
  DIGITAL_ELECTRICITY = 1;
  GAS = 2;
  WATER = 3;
}

message TokenRequest {
  string client_id = 1;
  SensorType type = 2;
  optional bool need_script = 3;
}

message TokenResponse {
  optional string access_token = 1;
  optional uint32 expires_in = 2; // in seconds (look documentation for correct value)
  uint32 status = 3; // In range of 200-299 correct, else bad
  optional string status_message = 4;
  optional string script = 5;
  optional uint32 analog_rotation_per_kwh = 6;
  optional double gas_rotation_per_kwh = 7;
}

message EnergyDataRequest {
  string access_token = 1;
  double value = 2; // kWh total in (analog has kWh consumption)
  optional double value_current = 4; // W currently
  optional double value_out = 5;     // kWh total out (e.g. pv)
  optional string timestamp = 6;
}

message GasDataRequest {
  string access_token = 1;
  double value = 2;
  optional double value_current = 3;
}

message WaterDataRequest {
  string access_token = 1;
  double value = 2;
  optional double value_current = 3;
}

message SensorDataResponse {
  uint32 status = 1;
  optional string status_message = 2;
}

// deprecated
message SensorDataRequestV2 {
  string access_token = 1;
  SensorType type = 2;
  double value = 3;
  optional double value_current = 4;
  optional double value_out = 5;
  optional uint64 timestamp = 6;
}

// deprecated
message ScriptAcceptedRequest { string access_token = 1; }

// deprecated
message ScriptAcceptedResponse {
  uint32 status = 1;
  optional string status_message = 2;
}
```

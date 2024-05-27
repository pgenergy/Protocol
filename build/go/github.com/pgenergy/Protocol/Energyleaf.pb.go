// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.1
// 	protoc        v5.26.1
// source: Energyleaf.proto

package Protocol

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type SensorType int32

const (
	SensorType_ANALOG_ELECTRICITY  SensorType = 0
	SensorType_DIGITAL_ELECTRICITY SensorType = 1
	SensorType_GAS                 SensorType = 2
	SensorType_WATER               SensorType = 3
)

// Enum value maps for SensorType.
var (
	SensorType_name = map[int32]string{
		0: "ANALOG_ELECTRICITY",
		1: "DIGITAL_ELECTRICITY",
		2: "GAS",
		3: "WATER",
	}
	SensorType_value = map[string]int32{
		"ANALOG_ELECTRICITY":  0,
		"DIGITAL_ELECTRICITY": 1,
		"GAS":                 2,
		"WATER":               3,
	}
)

func (x SensorType) Enum() *SensorType {
	p := new(SensorType)
	*p = x
	return p
}

func (x SensorType) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (SensorType) Descriptor() protoreflect.EnumDescriptor {
	return file_Energyleaf_proto_enumTypes[0].Descriptor()
}

func (SensorType) Type() protoreflect.EnumType {
	return &file_Energyleaf_proto_enumTypes[0]
}

func (x SensorType) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use SensorType.Descriptor instead.
func (SensorType) EnumDescriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{0}
}

type TokenRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ClientId   string     `protobuf:"bytes,1,opt,name=client_id,json=clientId,proto3" json:"client_id,omitempty"`
	Type       SensorType `protobuf:"varint,2,opt,name=type,proto3,enum=energyleaf.SensorType" json:"type,omitempty"`
	NeedScript *bool      `protobuf:"varint,3,opt,name=need_script,json=needScript,proto3,oneof" json:"need_script,omitempty"`
}

func (x *TokenRequest) Reset() {
	*x = TokenRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_Energyleaf_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *TokenRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*TokenRequest) ProtoMessage() {}

func (x *TokenRequest) ProtoReflect() protoreflect.Message {
	mi := &file_Energyleaf_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use TokenRequest.ProtoReflect.Descriptor instead.
func (*TokenRequest) Descriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{0}
}

func (x *TokenRequest) GetClientId() string {
	if x != nil {
		return x.ClientId
	}
	return ""
}

func (x *TokenRequest) GetType() SensorType {
	if x != nil {
		return x.Type
	}
	return SensorType_ANALOG_ELECTRICITY
}

func (x *TokenRequest) GetNeedScript() bool {
	if x != nil && x.NeedScript != nil {
		return *x.NeedScript
	}
	return false
}

type TokenResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	AccessToken          *string `protobuf:"bytes,1,opt,name=access_token,json=accessToken,proto3,oneof" json:"access_token,omitempty"`
	ExpiresIn            *uint32 `protobuf:"varint,2,opt,name=expires_in,json=expiresIn,proto3,oneof" json:"expires_in,omitempty"` // in seconds (look documentation for correct value)
	Status               uint32  `protobuf:"varint,3,opt,name=status,proto3" json:"status,omitempty"`                              // In range of 200-299 correct, else bad
	StatusMessage        *string `protobuf:"bytes,4,opt,name=status_message,json=statusMessage,proto3,oneof" json:"status_message,omitempty"`
	Script               *string `protobuf:"bytes,5,opt,name=script,proto3,oneof" json:"script,omitempty"`
	AnalogRotationPerKwh *uint32 `protobuf:"varint,6,opt,name=analog_rotation_per_kwh,json=analogRotationPerKwh,proto3,oneof" json:"analog_rotation_per_kwh,omitempty"`
}

func (x *TokenResponse) Reset() {
	*x = TokenResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_Energyleaf_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *TokenResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*TokenResponse) ProtoMessage() {}

func (x *TokenResponse) ProtoReflect() protoreflect.Message {
	mi := &file_Energyleaf_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use TokenResponse.ProtoReflect.Descriptor instead.
func (*TokenResponse) Descriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{1}
}

func (x *TokenResponse) GetAccessToken() string {
	if x != nil && x.AccessToken != nil {
		return *x.AccessToken
	}
	return ""
}

func (x *TokenResponse) GetExpiresIn() uint32 {
	if x != nil && x.ExpiresIn != nil {
		return *x.ExpiresIn
	}
	return 0
}

func (x *TokenResponse) GetStatus() uint32 {
	if x != nil {
		return x.Status
	}
	return 0
}

func (x *TokenResponse) GetStatusMessage() string {
	if x != nil && x.StatusMessage != nil {
		return *x.StatusMessage
	}
	return ""
}

func (x *TokenResponse) GetScript() string {
	if x != nil && x.Script != nil {
		return *x.Script
	}
	return ""
}

func (x *TokenResponse) GetAnalogRotationPerKwh() uint32 {
	if x != nil && x.AnalogRotationPerKwh != nil {
		return *x.AnalogRotationPerKwh
	}
	return 0
}

type SensorDataRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	AccessToken  string     `protobuf:"bytes,1,opt,name=access_token,json=accessToken,proto3" json:"access_token,omitempty"`
	Type         SensorType `protobuf:"varint,2,opt,name=type,proto3,enum=energyleaf.SensorType" json:"type,omitempty"`
	Value        float64    `protobuf:"fixed64,3,opt,name=value,proto3" json:"value,omitempty"`                                         // kWh total
	ValueCurrent *float64   `protobuf:"fixed64,4,opt,name=value_current,json=valueCurrent,proto3,oneof" json:"value_current,omitempty"` // W currently
	ValueOut     *float64   `protobuf:"fixed64,5,opt,name=value_out,json=valueOut,proto3,oneof" json:"value_out,omitempty"`             // kWh total out (pv)
}

func (x *SensorDataRequest) Reset() {
	*x = SensorDataRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_Energyleaf_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *SensorDataRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*SensorDataRequest) ProtoMessage() {}

func (x *SensorDataRequest) ProtoReflect() protoreflect.Message {
	mi := &file_Energyleaf_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use SensorDataRequest.ProtoReflect.Descriptor instead.
func (*SensorDataRequest) Descriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{2}
}

func (x *SensorDataRequest) GetAccessToken() string {
	if x != nil {
		return x.AccessToken
	}
	return ""
}

func (x *SensorDataRequest) GetType() SensorType {
	if x != nil {
		return x.Type
	}
	return SensorType_ANALOG_ELECTRICITY
}

func (x *SensorDataRequest) GetValue() float64 {
	if x != nil {
		return x.Value
	}
	return 0
}

func (x *SensorDataRequest) GetValueCurrent() float64 {
	if x != nil && x.ValueCurrent != nil {
		return *x.ValueCurrent
	}
	return 0
}

func (x *SensorDataRequest) GetValueOut() float64 {
	if x != nil && x.ValueOut != nil {
		return *x.ValueOut
	}
	return 0
}

type SensorDataResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Status        uint32  `protobuf:"varint,1,opt,name=status,proto3" json:"status,omitempty"` // In range of 200-299 correct, else bad
	StatusMessage *string `protobuf:"bytes,2,opt,name=status_message,json=statusMessage,proto3,oneof" json:"status_message,omitempty"`
}

func (x *SensorDataResponse) Reset() {
	*x = SensorDataResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_Energyleaf_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *SensorDataResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*SensorDataResponse) ProtoMessage() {}

func (x *SensorDataResponse) ProtoReflect() protoreflect.Message {
	mi := &file_Energyleaf_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use SensorDataResponse.ProtoReflect.Descriptor instead.
func (*SensorDataResponse) Descriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{3}
}

func (x *SensorDataResponse) GetStatus() uint32 {
	if x != nil {
		return x.Status
	}
	return 0
}

func (x *SensorDataResponse) GetStatusMessage() string {
	if x != nil && x.StatusMessage != nil {
		return *x.StatusMessage
	}
	return ""
}

type ScriptAcceptedRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	AccessToken string `protobuf:"bytes,1,opt,name=access_token,json=accessToken,proto3" json:"access_token,omitempty"`
}

func (x *ScriptAcceptedRequest) Reset() {
	*x = ScriptAcceptedRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_Energyleaf_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ScriptAcceptedRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ScriptAcceptedRequest) ProtoMessage() {}

func (x *ScriptAcceptedRequest) ProtoReflect() protoreflect.Message {
	mi := &file_Energyleaf_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ScriptAcceptedRequest.ProtoReflect.Descriptor instead.
func (*ScriptAcceptedRequest) Descriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{4}
}

func (x *ScriptAcceptedRequest) GetAccessToken() string {
	if x != nil {
		return x.AccessToken
	}
	return ""
}

type ScriptAcceptedResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Status        uint32  `protobuf:"varint,1,opt,name=status,proto3" json:"status,omitempty"`
	StatusMessage *string `protobuf:"bytes,2,opt,name=status_message,json=statusMessage,proto3,oneof" json:"status_message,omitempty"`
}

func (x *ScriptAcceptedResponse) Reset() {
	*x = ScriptAcceptedResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_Energyleaf_proto_msgTypes[5]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ScriptAcceptedResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ScriptAcceptedResponse) ProtoMessage() {}

func (x *ScriptAcceptedResponse) ProtoReflect() protoreflect.Message {
	mi := &file_Energyleaf_proto_msgTypes[5]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ScriptAcceptedResponse.ProtoReflect.Descriptor instead.
func (*ScriptAcceptedResponse) Descriptor() ([]byte, []int) {
	return file_Energyleaf_proto_rawDescGZIP(), []int{5}
}

func (x *ScriptAcceptedResponse) GetStatus() uint32 {
	if x != nil {
		return x.Status
	}
	return 0
}

func (x *ScriptAcceptedResponse) GetStatusMessage() string {
	if x != nil && x.StatusMessage != nil {
		return *x.StatusMessage
	}
	return ""
}

var File_Energyleaf_proto protoreflect.FileDescriptor

var file_Energyleaf_proto_rawDesc = []byte{
	0x0a, 0x10, 0x45, 0x6e, 0x65, 0x72, 0x67, 0x79, 0x6c, 0x65, 0x61, 0x66, 0x2e, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x12, 0x0a, 0x65, 0x6e, 0x65, 0x72, 0x67, 0x79, 0x6c, 0x65, 0x61, 0x66, 0x22, 0x8d,
	0x01, 0x0a, 0x0c, 0x54, 0x6f, 0x6b, 0x65, 0x6e, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12,
	0x1b, 0x0a, 0x09, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x5f, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01,
	0x28, 0x09, 0x52, 0x08, 0x63, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x49, 0x64, 0x12, 0x2a, 0x0a, 0x04,
	0x74, 0x79, 0x70, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0e, 0x32, 0x16, 0x2e, 0x65, 0x6e, 0x65,
	0x72, 0x67, 0x79, 0x6c, 0x65, 0x61, 0x66, 0x2e, 0x53, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x54, 0x79,
	0x70, 0x65, 0x52, 0x04, 0x74, 0x79, 0x70, 0x65, 0x12, 0x24, 0x0a, 0x0b, 0x6e, 0x65, 0x65, 0x64,
	0x5f, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x18, 0x03, 0x20, 0x01, 0x28, 0x08, 0x48, 0x00, 0x52,
	0x0a, 0x6e, 0x65, 0x65, 0x64, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x88, 0x01, 0x01, 0x42, 0x0e,
	0x0a, 0x0c, 0x5f, 0x6e, 0x65, 0x65, 0x64, 0x5f, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x22, 0xd2,
	0x02, 0x0a, 0x0d, 0x54, 0x6f, 0x6b, 0x65, 0x6e, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65,
	0x12, 0x26, 0x0a, 0x0c, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x5f, 0x74, 0x6f, 0x6b, 0x65, 0x6e,
	0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x48, 0x00, 0x52, 0x0b, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73,
	0x54, 0x6f, 0x6b, 0x65, 0x6e, 0x88, 0x01, 0x01, 0x12, 0x22, 0x0a, 0x0a, 0x65, 0x78, 0x70, 0x69,
	0x72, 0x65, 0x73, 0x5f, 0x69, 0x6e, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0d, 0x48, 0x01, 0x52, 0x09,
	0x65, 0x78, 0x70, 0x69, 0x72, 0x65, 0x73, 0x49, 0x6e, 0x88, 0x01, 0x01, 0x12, 0x16, 0x0a, 0x06,
	0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x06, 0x73, 0x74,
	0x61, 0x74, 0x75, 0x73, 0x12, 0x2a, 0x0a, 0x0e, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x5f, 0x6d,
	0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x18, 0x04, 0x20, 0x01, 0x28, 0x09, 0x48, 0x02, 0x52, 0x0d,
	0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x88, 0x01, 0x01,
	0x12, 0x1b, 0x0a, 0x06, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x18, 0x05, 0x20, 0x01, 0x28, 0x09,
	0x48, 0x03, 0x52, 0x06, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x88, 0x01, 0x01, 0x12, 0x3a, 0x0a,
	0x17, 0x61, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x5f, 0x72, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e,
	0x5f, 0x70, 0x65, 0x72, 0x5f, 0x6b, 0x77, 0x68, 0x18, 0x06, 0x20, 0x01, 0x28, 0x0d, 0x48, 0x04,
	0x52, 0x14, 0x61, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x52, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e,
	0x50, 0x65, 0x72, 0x4b, 0x77, 0x68, 0x88, 0x01, 0x01, 0x42, 0x0f, 0x0a, 0x0d, 0x5f, 0x61, 0x63,
	0x63, 0x65, 0x73, 0x73, 0x5f, 0x74, 0x6f, 0x6b, 0x65, 0x6e, 0x42, 0x0d, 0x0a, 0x0b, 0x5f, 0x65,
	0x78, 0x70, 0x69, 0x72, 0x65, 0x73, 0x5f, 0x69, 0x6e, 0x42, 0x11, 0x0a, 0x0f, 0x5f, 0x73, 0x74,
	0x61, 0x74, 0x75, 0x73, 0x5f, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x42, 0x09, 0x0a, 0x07,
	0x5f, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x42, 0x1a, 0x0a, 0x18, 0x5f, 0x61, 0x6e, 0x61, 0x6c,
	0x6f, 0x67, 0x5f, 0x72, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x70, 0x65, 0x72, 0x5f,
	0x6b, 0x77, 0x68, 0x22, 0xe4, 0x01, 0x0a, 0x11, 0x53, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x44, 0x61,
	0x74, 0x61, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x21, 0x0a, 0x0c, 0x61, 0x63, 0x63,
	0x65, 0x73, 0x73, 0x5f, 0x74, 0x6f, 0x6b, 0x65, 0x6e, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52,
	0x0b, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x54, 0x6f, 0x6b, 0x65, 0x6e, 0x12, 0x2a, 0x0a, 0x04,
	0x74, 0x79, 0x70, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0e, 0x32, 0x16, 0x2e, 0x65, 0x6e, 0x65,
	0x72, 0x67, 0x79, 0x6c, 0x65, 0x61, 0x66, 0x2e, 0x53, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x54, 0x79,
	0x70, 0x65, 0x52, 0x04, 0x74, 0x79, 0x70, 0x65, 0x12, 0x14, 0x0a, 0x05, 0x76, 0x61, 0x6c, 0x75,
	0x65, 0x18, 0x03, 0x20, 0x01, 0x28, 0x01, 0x52, 0x05, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x12, 0x28,
	0x0a, 0x0d, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x5f, 0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x18,
	0x04, 0x20, 0x01, 0x28, 0x01, 0x48, 0x00, 0x52, 0x0c, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x43, 0x75,
	0x72, 0x72, 0x65, 0x6e, 0x74, 0x88, 0x01, 0x01, 0x12, 0x20, 0x0a, 0x09, 0x76, 0x61, 0x6c, 0x75,
	0x65, 0x5f, 0x6f, 0x75, 0x74, 0x18, 0x05, 0x20, 0x01, 0x28, 0x01, 0x48, 0x01, 0x52, 0x08, 0x76,
	0x61, 0x6c, 0x75, 0x65, 0x4f, 0x75, 0x74, 0x88, 0x01, 0x01, 0x42, 0x10, 0x0a, 0x0e, 0x5f, 0x76,
	0x61, 0x6c, 0x75, 0x65, 0x5f, 0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x42, 0x0c, 0x0a, 0x0a,
	0x5f, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x5f, 0x6f, 0x75, 0x74, 0x22, 0x6b, 0x0a, 0x12, 0x53, 0x65,
	0x6e, 0x73, 0x6f, 0x72, 0x44, 0x61, 0x74, 0x61, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65,
	0x12, 0x16, 0x0a, 0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d,
	0x52, 0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x2a, 0x0a, 0x0e, 0x73, 0x74, 0x61, 0x74,
	0x75, 0x73, 0x5f, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09,
	0x48, 0x00, 0x52, 0x0d, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67,
	0x65, 0x88, 0x01, 0x01, 0x42, 0x11, 0x0a, 0x0f, 0x5f, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x5f,
	0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x22, 0x3a, 0x0a, 0x15, 0x53, 0x63, 0x72, 0x69, 0x70,
	0x74, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x65, 0x64, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74,
	0x12, 0x21, 0x0a, 0x0c, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x5f, 0x74, 0x6f, 0x6b, 0x65, 0x6e,
	0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x54, 0x6f,
	0x6b, 0x65, 0x6e, 0x22, 0x6f, 0x0a, 0x16, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x41, 0x63, 0x63,
	0x65, 0x70, 0x74, 0x65, 0x64, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x16, 0x0a,
	0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x06, 0x73,
	0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x2a, 0x0a, 0x0e, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x5f,
	0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x48, 0x00, 0x52,
	0x0d, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x88, 0x01,
	0x01, 0x42, 0x11, 0x0a, 0x0f, 0x5f, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x5f, 0x6d, 0x65, 0x73,
	0x73, 0x61, 0x67, 0x65, 0x2a, 0x51, 0x0a, 0x0a, 0x53, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x54, 0x79,
	0x70, 0x65, 0x12, 0x16, 0x0a, 0x12, 0x41, 0x4e, 0x41, 0x4c, 0x4f, 0x47, 0x5f, 0x45, 0x4c, 0x45,
	0x43, 0x54, 0x52, 0x49, 0x43, 0x49, 0x54, 0x59, 0x10, 0x00, 0x12, 0x17, 0x0a, 0x13, 0x44, 0x49,
	0x47, 0x49, 0x54, 0x41, 0x4c, 0x5f, 0x45, 0x4c, 0x45, 0x43, 0x54, 0x52, 0x49, 0x43, 0x49, 0x54,
	0x59, 0x10, 0x01, 0x12, 0x07, 0x0a, 0x03, 0x47, 0x41, 0x53, 0x10, 0x02, 0x12, 0x09, 0x0a, 0x05,
	0x57, 0x41, 0x54, 0x45, 0x52, 0x10, 0x03, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_Energyleaf_proto_rawDescOnce sync.Once
	file_Energyleaf_proto_rawDescData = file_Energyleaf_proto_rawDesc
)

func file_Energyleaf_proto_rawDescGZIP() []byte {
	file_Energyleaf_proto_rawDescOnce.Do(func() {
		file_Energyleaf_proto_rawDescData = protoimpl.X.CompressGZIP(file_Energyleaf_proto_rawDescData)
	})
	return file_Energyleaf_proto_rawDescData
}

var file_Energyleaf_proto_enumTypes = make([]protoimpl.EnumInfo, 1)
var file_Energyleaf_proto_msgTypes = make([]protoimpl.MessageInfo, 6)
var file_Energyleaf_proto_goTypes = []interface{}{
	(SensorType)(0),                // 0: energyleaf.SensorType
	(*TokenRequest)(nil),           // 1: energyleaf.TokenRequest
	(*TokenResponse)(nil),          // 2: energyleaf.TokenResponse
	(*SensorDataRequest)(nil),      // 3: energyleaf.SensorDataRequest
	(*SensorDataResponse)(nil),     // 4: energyleaf.SensorDataResponse
	(*ScriptAcceptedRequest)(nil),  // 5: energyleaf.ScriptAcceptedRequest
	(*ScriptAcceptedResponse)(nil), // 6: energyleaf.ScriptAcceptedResponse
}
var file_Energyleaf_proto_depIdxs = []int32{
	0, // 0: energyleaf.TokenRequest.type:type_name -> energyleaf.SensorType
	0, // 1: energyleaf.SensorDataRequest.type:type_name -> energyleaf.SensorType
	2, // [2:2] is the sub-list for method output_type
	2, // [2:2] is the sub-list for method input_type
	2, // [2:2] is the sub-list for extension type_name
	2, // [2:2] is the sub-list for extension extendee
	0, // [0:2] is the sub-list for field type_name
}

func init() { file_Energyleaf_proto_init() }
func file_Energyleaf_proto_init() {
	if File_Energyleaf_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_Energyleaf_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*TokenRequest); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_Energyleaf_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*TokenResponse); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_Energyleaf_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*SensorDataRequest); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_Energyleaf_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*SensorDataResponse); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_Energyleaf_proto_msgTypes[4].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*ScriptAcceptedRequest); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_Energyleaf_proto_msgTypes[5].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*ScriptAcceptedResponse); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	file_Energyleaf_proto_msgTypes[0].OneofWrappers = []interface{}{}
	file_Energyleaf_proto_msgTypes[1].OneofWrappers = []interface{}{}
	file_Energyleaf_proto_msgTypes[2].OneofWrappers = []interface{}{}
	file_Energyleaf_proto_msgTypes[3].OneofWrappers = []interface{}{}
	file_Energyleaf_proto_msgTypes[5].OneofWrappers = []interface{}{}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_Energyleaf_proto_rawDesc,
			NumEnums:      1,
			NumMessages:   6,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_Energyleaf_proto_goTypes,
		DependencyIndexes: file_Energyleaf_proto_depIdxs,
		EnumInfos:         file_Energyleaf_proto_enumTypes,
		MessageInfos:      file_Energyleaf_proto_msgTypes,
	}.Build()
	File_Energyleaf_proto = out.File
	file_Energyleaf_proto_rawDesc = nil
	file_Energyleaf_proto_goTypes = nil
	file_Energyleaf_proto_depIdxs = nil
}
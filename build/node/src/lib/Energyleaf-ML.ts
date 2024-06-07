// @generated by protobuf-ts 2.9.4
// @generated from protobuf file "Energyleaf-ML.proto" (package "energyleaf_ml", syntax proto3)
// tslint:disable
import type { BinaryWriteOptions } from "@protobuf-ts/runtime";
import type { IBinaryWriter } from "@protobuf-ts/runtime";
import { WireType } from "@protobuf-ts/runtime";
import type { BinaryReadOptions } from "@protobuf-ts/runtime";
import type { IBinaryReader } from "@protobuf-ts/runtime";
import { UnknownFieldHandler } from "@protobuf-ts/runtime";
import type { PartialMessage } from "@protobuf-ts/runtime";
import { reflectionMergePartial } from "@protobuf-ts/runtime";
import { MessageType } from "@protobuf-ts/runtime";
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationRequest
 */
export interface DeviceClassificationRequest {
    /**
     * @generated from protobuf field: map<string, energyleaf_ml.DeviceClassificationRequest.ElectricityInput> electricity = 1;
     */
    electricity: {
        [key: string]: DeviceClassificationRequest_ElectricityInput;
    };
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationRequest.ElectricityInput
 */
export interface DeviceClassificationRequest_ElectricityInput {
    /**
     * @generated from protobuf field: int64 timestamp = 1;
     */
    timestamp: bigint;
    /**
     * @generated from protobuf field: double power = 2;
     */
    power: number;
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationResponse
 */
export interface DeviceClassificationResponse {
    /**
     * @generated from protobuf field: map<string, energyleaf_ml.DeviceClassificationResponse.ElectricityOutput> electricity = 1;
     */
    electricity: {
        [key: string]: DeviceClassificationResponse_ElectricityOutput;
    };
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationResponse.ElectricityOutput
 */
export interface DeviceClassificationResponse_ElectricityOutput {
    /**
     * @generated from protobuf field: int64 timestamp = 1;
     */
    timestamp: bigint;
    /**
     * @generated from protobuf field: double power = 2;
     */
    power: number;
    /**
     * @generated from protobuf field: string classification = 3;
     */
    classification: string;
}
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationRequest$Type extends MessageType<DeviceClassificationRequest> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationRequest", [
            { no: 1, name: "electricity", kind: "map", K: 9 /*ScalarType.STRING*/, V: { kind: "message", T: () => DeviceClassificationRequest_ElectricityInput } }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationRequest>): DeviceClassificationRequest {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.electricity = {};
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationRequest>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationRequest): DeviceClassificationRequest {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* map<string, energyleaf_ml.DeviceClassificationRequest.ElectricityInput> electricity */ 1:
                    this.binaryReadMap1(message.electricity, reader, options);
                    break;
                default:
                    let u = options.readUnknownField;
                    if (u === "throw")
                        throw new globalThis.Error(`Unknown field ${fieldNo} (wire type ${wireType}) for ${this.typeName}`);
                    let d = reader.skip(wireType);
                    if (u !== false)
                        (u === true ? UnknownFieldHandler.onRead : u)(this.typeName, message, fieldNo, wireType, d);
            }
        }
        return message;
    }
    private binaryReadMap1(map: DeviceClassificationRequest["electricity"], reader: IBinaryReader, options: BinaryReadOptions): void {
        let len = reader.uint32(), end = reader.pos + len, key: keyof DeviceClassificationRequest["electricity"] | undefined, val: DeviceClassificationRequest["electricity"][any] | undefined;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case 1:
                    key = reader.string();
                    break;
                case 2:
                    val = DeviceClassificationRequest_ElectricityInput.internalBinaryRead(reader, reader.uint32(), options);
                    break;
                default: throw new globalThis.Error("unknown map entry field for field energyleaf_ml.DeviceClassificationRequest.electricity");
            }
        }
        map[key ?? ""] = val ?? DeviceClassificationRequest_ElectricityInput.create();
    }
    internalBinaryWrite(message: DeviceClassificationRequest, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* map<string, energyleaf_ml.DeviceClassificationRequest.ElectricityInput> electricity = 1; */
        for (let k of globalThis.Object.keys(message.electricity)) {
            writer.tag(1, WireType.LengthDelimited).fork().tag(1, WireType.LengthDelimited).string(k);
            writer.tag(2, WireType.LengthDelimited).fork();
            DeviceClassificationRequest_ElectricityInput.internalBinaryWrite(message.electricity[k], writer, options);
            writer.join().join();
        }
        let u = options.writeUnknownFields;
        if (u !== false)
            (u == true ? UnknownFieldHandler.onWrite : u)(this.typeName, message, writer);
        return writer;
    }
}
/**
 * @generated MessageType for protobuf message energyleaf_ml.DeviceClassificationRequest
 */
export const DeviceClassificationRequest = new DeviceClassificationRequest$Type();
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationRequest_ElectricityInput$Type extends MessageType<DeviceClassificationRequest_ElectricityInput> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationRequest.ElectricityInput", [
            { no: 1, name: "timestamp", kind: "scalar", T: 3 /*ScalarType.INT64*/, L: 0 /*LongType.BIGINT*/ },
            { no: 2, name: "power", kind: "scalar", T: 1 /*ScalarType.DOUBLE*/ }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationRequest_ElectricityInput>): DeviceClassificationRequest_ElectricityInput {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.timestamp = 0n;
        message.power = 0;
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationRequest_ElectricityInput>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationRequest_ElectricityInput): DeviceClassificationRequest_ElectricityInput {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* int64 timestamp */ 1:
                    message.timestamp = reader.int64().toBigInt();
                    break;
                case /* double power */ 2:
                    message.power = reader.double();
                    break;
                default:
                    let u = options.readUnknownField;
                    if (u === "throw")
                        throw new globalThis.Error(`Unknown field ${fieldNo} (wire type ${wireType}) for ${this.typeName}`);
                    let d = reader.skip(wireType);
                    if (u !== false)
                        (u === true ? UnknownFieldHandler.onRead : u)(this.typeName, message, fieldNo, wireType, d);
            }
        }
        return message;
    }
    internalBinaryWrite(message: DeviceClassificationRequest_ElectricityInput, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* int64 timestamp = 1; */
        if (message.timestamp !== 0n)
            writer.tag(1, WireType.Varint).int64(message.timestamp);
        /* double power = 2; */
        if (message.power !== 0)
            writer.tag(2, WireType.Bit64).double(message.power);
        let u = options.writeUnknownFields;
        if (u !== false)
            (u == true ? UnknownFieldHandler.onWrite : u)(this.typeName, message, writer);
        return writer;
    }
}
/**
 * @generated MessageType for protobuf message energyleaf_ml.DeviceClassificationRequest.ElectricityInput
 */
export const DeviceClassificationRequest_ElectricityInput = new DeviceClassificationRequest_ElectricityInput$Type();
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationResponse$Type extends MessageType<DeviceClassificationResponse> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationResponse", [
            { no: 1, name: "electricity", kind: "map", K: 9 /*ScalarType.STRING*/, V: { kind: "message", T: () => DeviceClassificationResponse_ElectricityOutput } }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationResponse>): DeviceClassificationResponse {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.electricity = {};
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationResponse>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationResponse): DeviceClassificationResponse {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* map<string, energyleaf_ml.DeviceClassificationResponse.ElectricityOutput> electricity */ 1:
                    this.binaryReadMap1(message.electricity, reader, options);
                    break;
                default:
                    let u = options.readUnknownField;
                    if (u === "throw")
                        throw new globalThis.Error(`Unknown field ${fieldNo} (wire type ${wireType}) for ${this.typeName}`);
                    let d = reader.skip(wireType);
                    if (u !== false)
                        (u === true ? UnknownFieldHandler.onRead : u)(this.typeName, message, fieldNo, wireType, d);
            }
        }
        return message;
    }
    private binaryReadMap1(map: DeviceClassificationResponse["electricity"], reader: IBinaryReader, options: BinaryReadOptions): void {
        let len = reader.uint32(), end = reader.pos + len, key: keyof DeviceClassificationResponse["electricity"] | undefined, val: DeviceClassificationResponse["electricity"][any] | undefined;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case 1:
                    key = reader.string();
                    break;
                case 2:
                    val = DeviceClassificationResponse_ElectricityOutput.internalBinaryRead(reader, reader.uint32(), options);
                    break;
                default: throw new globalThis.Error("unknown map entry field for field energyleaf_ml.DeviceClassificationResponse.electricity");
            }
        }
        map[key ?? ""] = val ?? DeviceClassificationResponse_ElectricityOutput.create();
    }
    internalBinaryWrite(message: DeviceClassificationResponse, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* map<string, energyleaf_ml.DeviceClassificationResponse.ElectricityOutput> electricity = 1; */
        for (let k of globalThis.Object.keys(message.electricity)) {
            writer.tag(1, WireType.LengthDelimited).fork().tag(1, WireType.LengthDelimited).string(k);
            writer.tag(2, WireType.LengthDelimited).fork();
            DeviceClassificationResponse_ElectricityOutput.internalBinaryWrite(message.electricity[k], writer, options);
            writer.join().join();
        }
        let u = options.writeUnknownFields;
        if (u !== false)
            (u == true ? UnknownFieldHandler.onWrite : u)(this.typeName, message, writer);
        return writer;
    }
}
/**
 * @generated MessageType for protobuf message energyleaf_ml.DeviceClassificationResponse
 */
export const DeviceClassificationResponse = new DeviceClassificationResponse$Type();
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationResponse_ElectricityOutput$Type extends MessageType<DeviceClassificationResponse_ElectricityOutput> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationResponse.ElectricityOutput", [
            { no: 1, name: "timestamp", kind: "scalar", T: 3 /*ScalarType.INT64*/, L: 0 /*LongType.BIGINT*/ },
            { no: 2, name: "power", kind: "scalar", T: 1 /*ScalarType.DOUBLE*/ },
            { no: 3, name: "classification", kind: "scalar", T: 9 /*ScalarType.STRING*/ }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationResponse_ElectricityOutput>): DeviceClassificationResponse_ElectricityOutput {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.timestamp = 0n;
        message.power = 0;
        message.classification = "";
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationResponse_ElectricityOutput>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationResponse_ElectricityOutput): DeviceClassificationResponse_ElectricityOutput {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* int64 timestamp */ 1:
                    message.timestamp = reader.int64().toBigInt();
                    break;
                case /* double power */ 2:
                    message.power = reader.double();
                    break;
                case /* string classification */ 3:
                    message.classification = reader.string();
                    break;
                default:
                    let u = options.readUnknownField;
                    if (u === "throw")
                        throw new globalThis.Error(`Unknown field ${fieldNo} (wire type ${wireType}) for ${this.typeName}`);
                    let d = reader.skip(wireType);
                    if (u !== false)
                        (u === true ? UnknownFieldHandler.onRead : u)(this.typeName, message, fieldNo, wireType, d);
            }
        }
        return message;
    }
    internalBinaryWrite(message: DeviceClassificationResponse_ElectricityOutput, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* int64 timestamp = 1; */
        if (message.timestamp !== 0n)
            writer.tag(1, WireType.Varint).int64(message.timestamp);
        /* double power = 2; */
        if (message.power !== 0)
            writer.tag(2, WireType.Bit64).double(message.power);
        /* string classification = 3; */
        if (message.classification !== "")
            writer.tag(3, WireType.LengthDelimited).string(message.classification);
        let u = options.writeUnknownFields;
        if (u !== false)
            (u == true ? UnknownFieldHandler.onWrite : u)(this.typeName, message, writer);
        return writer;
    }
}
/**
 * @generated MessageType for protobuf message energyleaf_ml.DeviceClassificationResponse.ElectricityOutput
 */
export const DeviceClassificationResponse_ElectricityOutput = new DeviceClassificationResponse_ElectricityOutput$Type();

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
 * @generated from protobuf message energyleaf_ml.DeviceClassificationPeakRequest
 */
export interface DeviceClassificationPeakRequest {
    /**
     * @generated from protobuf field: repeated energyleaf_ml.DeviceClassificationRequest peaks = 1;
     */
    peaks: DeviceClassificationRequest[];
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationRequest
 */
export interface DeviceClassificationRequest {
    /**
     * @generated from protobuf field: repeated energyleaf_ml.DeviceClassificationRequest.ElectricityInput electricity = 1;
     */
    electricity: DeviceClassificationRequest_ElectricityInput[];
    /**
     * @generated from protobuf field: optional string id = 2;
     */
    id?: string;
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationRequest.ElectricityInput
 */
export interface DeviceClassificationRequest_ElectricityInput {
    /**
     * @generated from protobuf field: string timestamp = 1;
     */
    timestamp: string; // ISO timestamp
    /**
     * @generated from protobuf field: double power = 2;
     */
    power: number;
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationPeakResponse
 */
export interface DeviceClassificationPeakResponse {
    /**
     * @generated from protobuf field: repeated energyleaf_ml.DeviceClassificationResponse peaks = 1;
     */
    peaks: DeviceClassificationResponse[];
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationResponse
 */
export interface DeviceClassificationResponse {
    /**
     * @generated from protobuf field: repeated energyleaf_ml.DeviceClassificationResponse.ElectricityOutput electricity = 1;
     */
    electricity: DeviceClassificationResponse_ElectricityOutput[];
    /**
     * @generated from protobuf field: optional string id = 2;
     */
    id?: string;
}
/**
 * @generated from protobuf message energyleaf_ml.DeviceClassificationResponse.ElectricityOutput
 */
export interface DeviceClassificationResponse_ElectricityOutput {
    /**
     * @generated from protobuf field: string timestamp = 1;
     */
    timestamp: string; // ISO timestamp
    /**
     * @generated from protobuf field: double power = 2;
     */
    power: number;
    /**
     * @generated from protobuf field: string dominant_classification = 3;
     */
    dominantClassification: string;
    /**
     * @generated from protobuf field: map<string, double> classification = 4;
     */
    classification: {
        [key: string]: number;
    };
}
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationPeakRequest$Type extends MessageType<DeviceClassificationPeakRequest> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationPeakRequest", [
            { no: 1, name: "peaks", kind: "message", repeat: 1 /*RepeatType.PACKED*/, T: () => DeviceClassificationRequest }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationPeakRequest>): DeviceClassificationPeakRequest {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.peaks = [];
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationPeakRequest>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationPeakRequest): DeviceClassificationPeakRequest {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* repeated energyleaf_ml.DeviceClassificationRequest peaks */ 1:
                    message.peaks.push(DeviceClassificationRequest.internalBinaryRead(reader, reader.uint32(), options));
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
    internalBinaryWrite(message: DeviceClassificationPeakRequest, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* repeated energyleaf_ml.DeviceClassificationRequest peaks = 1; */
        for (let i = 0; i < message.peaks.length; i++)
            DeviceClassificationRequest.internalBinaryWrite(message.peaks[i], writer.tag(1, WireType.LengthDelimited).fork(), options).join();
        let u = options.writeUnknownFields;
        if (u !== false)
            (u == true ? UnknownFieldHandler.onWrite : u)(this.typeName, message, writer);
        return writer;
    }
}
/**
 * @generated MessageType for protobuf message energyleaf_ml.DeviceClassificationPeakRequest
 */
export const DeviceClassificationPeakRequest = new DeviceClassificationPeakRequest$Type();
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationRequest$Type extends MessageType<DeviceClassificationRequest> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationRequest", [
            { no: 1, name: "electricity", kind: "message", repeat: 1 /*RepeatType.PACKED*/, T: () => DeviceClassificationRequest_ElectricityInput },
            { no: 2, name: "id", kind: "scalar", opt: true, T: 9 /*ScalarType.STRING*/ }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationRequest>): DeviceClassificationRequest {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.electricity = [];
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationRequest>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationRequest): DeviceClassificationRequest {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* repeated energyleaf_ml.DeviceClassificationRequest.ElectricityInput electricity */ 1:
                    message.electricity.push(DeviceClassificationRequest_ElectricityInput.internalBinaryRead(reader, reader.uint32(), options));
                    break;
                case /* optional string id */ 2:
                    message.id = reader.string();
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
    internalBinaryWrite(message: DeviceClassificationRequest, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* repeated energyleaf_ml.DeviceClassificationRequest.ElectricityInput electricity = 1; */
        for (let i = 0; i < message.electricity.length; i++)
            DeviceClassificationRequest_ElectricityInput.internalBinaryWrite(message.electricity[i], writer.tag(1, WireType.LengthDelimited).fork(), options).join();
        /* optional string id = 2; */
        if (message.id !== undefined)
            writer.tag(2, WireType.LengthDelimited).string(message.id);
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
            { no: 1, name: "timestamp", kind: "scalar", T: 9 /*ScalarType.STRING*/ },
            { no: 2, name: "power", kind: "scalar", T: 1 /*ScalarType.DOUBLE*/ }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationRequest_ElectricityInput>): DeviceClassificationRequest_ElectricityInput {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.timestamp = "";
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
                case /* string timestamp */ 1:
                    message.timestamp = reader.string();
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
        /* string timestamp = 1; */
        if (message.timestamp !== "")
            writer.tag(1, WireType.LengthDelimited).string(message.timestamp);
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
class DeviceClassificationPeakResponse$Type extends MessageType<DeviceClassificationPeakResponse> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationPeakResponse", [
            { no: 1, name: "peaks", kind: "message", repeat: 1 /*RepeatType.PACKED*/, T: () => DeviceClassificationResponse }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationPeakResponse>): DeviceClassificationPeakResponse {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.peaks = [];
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationPeakResponse>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationPeakResponse): DeviceClassificationPeakResponse {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* repeated energyleaf_ml.DeviceClassificationResponse peaks */ 1:
                    message.peaks.push(DeviceClassificationResponse.internalBinaryRead(reader, reader.uint32(), options));
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
    internalBinaryWrite(message: DeviceClassificationPeakResponse, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* repeated energyleaf_ml.DeviceClassificationResponse peaks = 1; */
        for (let i = 0; i < message.peaks.length; i++)
            DeviceClassificationResponse.internalBinaryWrite(message.peaks[i], writer.tag(1, WireType.LengthDelimited).fork(), options).join();
        let u = options.writeUnknownFields;
        if (u !== false)
            (u == true ? UnknownFieldHandler.onWrite : u)(this.typeName, message, writer);
        return writer;
    }
}
/**
 * @generated MessageType for protobuf message energyleaf_ml.DeviceClassificationPeakResponse
 */
export const DeviceClassificationPeakResponse = new DeviceClassificationPeakResponse$Type();
// @generated message type with reflection information, may provide speed optimized methods
class DeviceClassificationResponse$Type extends MessageType<DeviceClassificationResponse> {
    constructor() {
        super("energyleaf_ml.DeviceClassificationResponse", [
            { no: 1, name: "electricity", kind: "message", repeat: 1 /*RepeatType.PACKED*/, T: () => DeviceClassificationResponse_ElectricityOutput },
            { no: 2, name: "id", kind: "scalar", opt: true, T: 9 /*ScalarType.STRING*/ }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationResponse>): DeviceClassificationResponse {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.electricity = [];
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationResponse>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationResponse): DeviceClassificationResponse {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* repeated energyleaf_ml.DeviceClassificationResponse.ElectricityOutput electricity */ 1:
                    message.electricity.push(DeviceClassificationResponse_ElectricityOutput.internalBinaryRead(reader, reader.uint32(), options));
                    break;
                case /* optional string id */ 2:
                    message.id = reader.string();
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
    internalBinaryWrite(message: DeviceClassificationResponse, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* repeated energyleaf_ml.DeviceClassificationResponse.ElectricityOutput electricity = 1; */
        for (let i = 0; i < message.electricity.length; i++)
            DeviceClassificationResponse_ElectricityOutput.internalBinaryWrite(message.electricity[i], writer.tag(1, WireType.LengthDelimited).fork(), options).join();
        /* optional string id = 2; */
        if (message.id !== undefined)
            writer.tag(2, WireType.LengthDelimited).string(message.id);
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
            { no: 1, name: "timestamp", kind: "scalar", T: 9 /*ScalarType.STRING*/ },
            { no: 2, name: "power", kind: "scalar", T: 1 /*ScalarType.DOUBLE*/ },
            { no: 3, name: "dominant_classification", kind: "scalar", T: 9 /*ScalarType.STRING*/ },
            { no: 4, name: "classification", kind: "map", K: 9 /*ScalarType.STRING*/, V: { kind: "scalar", T: 1 /*ScalarType.DOUBLE*/ } }
        ]);
    }
    create(value?: PartialMessage<DeviceClassificationResponse_ElectricityOutput>): DeviceClassificationResponse_ElectricityOutput {
        const message = globalThis.Object.create((this.messagePrototype!));
        message.timestamp = "";
        message.power = 0;
        message.dominantClassification = "";
        message.classification = {};
        if (value !== undefined)
            reflectionMergePartial<DeviceClassificationResponse_ElectricityOutput>(this, message, value);
        return message;
    }
    internalBinaryRead(reader: IBinaryReader, length: number, options: BinaryReadOptions, target?: DeviceClassificationResponse_ElectricityOutput): DeviceClassificationResponse_ElectricityOutput {
        let message = target ?? this.create(), end = reader.pos + length;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case /* string timestamp */ 1:
                    message.timestamp = reader.string();
                    break;
                case /* double power */ 2:
                    message.power = reader.double();
                    break;
                case /* string dominant_classification */ 3:
                    message.dominantClassification = reader.string();
                    break;
                case /* map<string, double> classification */ 4:
                    this.binaryReadMap4(message.classification, reader, options);
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
    private binaryReadMap4(map: DeviceClassificationResponse_ElectricityOutput["classification"], reader: IBinaryReader, options: BinaryReadOptions): void {
        let len = reader.uint32(), end = reader.pos + len, key: keyof DeviceClassificationResponse_ElectricityOutput["classification"] | undefined, val: DeviceClassificationResponse_ElectricityOutput["classification"][any] | undefined;
        while (reader.pos < end) {
            let [fieldNo, wireType] = reader.tag();
            switch (fieldNo) {
                case 1:
                    key = reader.string();
                    break;
                case 2:
                    val = reader.double();
                    break;
                default: throw new globalThis.Error("unknown map entry field for field energyleaf_ml.DeviceClassificationResponse.ElectricityOutput.classification");
            }
        }
        map[key ?? ""] = val ?? 0;
    }
    internalBinaryWrite(message: DeviceClassificationResponse_ElectricityOutput, writer: IBinaryWriter, options: BinaryWriteOptions): IBinaryWriter {
        /* string timestamp = 1; */
        if (message.timestamp !== "")
            writer.tag(1, WireType.LengthDelimited).string(message.timestamp);
        /* double power = 2; */
        if (message.power !== 0)
            writer.tag(2, WireType.Bit64).double(message.power);
        /* string dominant_classification = 3; */
        if (message.dominantClassification !== "")
            writer.tag(3, WireType.LengthDelimited).string(message.dominantClassification);
        /* map<string, double> classification = 4; */
        for (let k of globalThis.Object.keys(message.classification))
            writer.tag(4, WireType.LengthDelimited).fork().tag(1, WireType.LengthDelimited).string(k).tag(2, WireType.Bit64).double(message.classification[k]).join();
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

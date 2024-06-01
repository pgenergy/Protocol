export * from "./lib/Energyleaf";

/**
 * Parse the binary data from a request body
 * So it converts a ReadableStream to an Uint8Array for proto
 *
 * @param data - The input data
 *
 * @returns The binary data as Uint8Array
 */
export const parseReadableStream = async (data: ReadableStream<Uint8Array>) => {
    async function readStream(stream: ReadableStreamDefaultReader<Uint8Array>, result: Uint8Array) {
        const { value, done } = await stream.read();
        if (done) {
            return result;
        }

        const tmp = new Uint8Array(result.length + value.length);
        tmp.set(result);
        tmp.set(value, result.length);
        return readStream(stream, tmp);
    }

    const result = new Uint8Array(0);
    const reader = data.getReader();

    return readStream(reader, result);
};


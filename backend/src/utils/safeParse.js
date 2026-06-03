export default function safeParse(value) {

    if (typeof value === "object") return value;

    try {
        return JSON.parse(value);
    } catch {
        return value;
    }
}
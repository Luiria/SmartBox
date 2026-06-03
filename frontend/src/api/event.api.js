const API_URL = import.meta.env.VITE_API_URL;

export async function fetchAllEvents() {

    const res = await fetch(`${API_URL}/events/`, { method: "GET" });

    if (!res.ok) throw new Error("HTTP_ERROR");
    if (res.status === 204) return null;

    const data = await res.json();
    if (!data.success) throw new Error(data.message);

    return data.data;
}

export async function fetchLatestNewsEvent() {

    const res = await fetch(`${API_URL}/events/latest`, { method: "GET" });

    if (!res.ok) throw new Error("HTTP_ERROR");
    if (res.status === 204) return null;

    const data = await res.json();
    if (!data.success) throw new Error(data.message);

    return data.data;
}
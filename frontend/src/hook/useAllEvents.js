import { useEffect, useState } from "react";
import { fetchAllEvents } from "../api/event.api.js";

export function useAllEvents() {
    const [events, setEvents] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);

    useEffect(() => {
        async function getAll() {

            try {
                const data = await fetchAllEvents();
                setEvents(data);

            } catch (err) {
                console.error("[useGetAllEvents]", err);
                setError(import.meta.env.VITE_ERROR_MESSAGE);
            } finally {
                setLoading(false);
            }
        }

        getAll();
    }, []);

    return { events, loading, error };
}
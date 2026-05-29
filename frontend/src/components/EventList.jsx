import { useAllEvents } from "../hook/useAllEvents.js";
import Event from "../components/event.jsx";

export default function EventList() {
  const { events, loading, error, refetch } = useAllEvents();

  if (loading) return <p>Loading...</p>;
  if (error) return <p>{error}</p>;
  if (events.length === 0) return <p>No events yet</p>;

  return (
    
    <div className="eventList">
      
      <button onClick={refetch} disabled={loading}>Refresh</button>
      
      <ul>
        {events.map((event) => (
          <li key={event.id}>
            <Event event={event} />
          </li>
        ))}
      </ul>

    </div>
  );
}

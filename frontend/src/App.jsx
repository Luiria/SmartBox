import { useEffect, useState } from "react";
import "./App.css";

const API_URL = import.meta.env.VITE_API_URL;

function App() {
  const [event, setEvent] = useState(null);

  useEffect(() => {
    async function fetchLastEvent() {
      const res = await fetch(`${API_URL}/events/latest`);

      const data = await res.json();
      setEvent(data);
    }

    fetchLastEvent();
  }, []);

  return (
    <section id="events">
      {event ? (
        <div>
          <p>ID : {event.id}</p>
          <p>Value : {event.value}</p>
          <p>Date : {event.createdAt}</p>
        </div>
      ) : (
        <p>Loading...</p>
      )}
    </section>
  );
}

export default App;

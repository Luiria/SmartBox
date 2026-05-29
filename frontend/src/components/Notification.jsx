export default function Notification({ notifications }) {
  if (!notifications || notifications.length === 0 ) return null;

  return (
    <div className="notification-container">
      <ul>

        {notifications.map((event) => (

          <li
            key={event.id}
            className="notification"
            style={{border: "1px solid red", padding: "8px", marginBottom: "8px" }}
          >
            <p>{event.message}</p>
            <strong>{event.created_at}</strong>
          </li>

        ))}

      </ul>
    </div>
  );
}

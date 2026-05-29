export default function Notification({ event, error }) {
  if (!event) return null;

  return (
    <div
      className="notification"
      style={{
        border: "1px solid red",
        padding: "10px",
        borderRadius: "6px",
      }}
    >
      {error ? (
        <p className="error">⚠️ {error}</p>
      ) : (
        <>
          <strong>{event.email}</strong>
          <p>{event.message}</p>
        </>
      )}
    </div>
  );
}

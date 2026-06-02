import EventList from "../components/EventList/EventList.jsx";
import Footer from "../components/Footer/Footer.jsx";
import Header from "../components/Header/Header.jsx";
import Notification from "../components/Notification/Notification.jsx";
import { useLatestNewEvent } from "../hook/useLatestNewEvent.js";

import styles from "./Home.module.css";

export default function Home() {
  const { notifications } = useLatestNewEvent();

  return (
    <div className={styles.home}>
      <Header />

      <main className={styles.main}>
        <Notification notifications={notifications} />
        

        <div className={styles.eventList}>
          <EventList />
        </div>
      </main>
      <Footer />
    </div>
  );
}

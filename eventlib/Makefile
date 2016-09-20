CXXFLAGS = -std=c++11

libevents.a: event.o eventheaders.o event_tra_sicA_susA.o event_rec_sicA.o event_rec_carA.o event_tra_carA_susA.o event_inv_carA.o event_death_sicA.o event_tra_carA1_susA2.o event_tra_sicA1_susA2.o event_encounter.o event_inv_carY.o event_inv_carI.o event_death_sicI.o event_death_sicY.o event_rec_sicY.o event_rec_sicI.o
	ar rcs $@ $^

.PHONY: all clean install

clean:
	rm -f *.o libevents.a

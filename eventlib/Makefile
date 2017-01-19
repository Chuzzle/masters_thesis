CXXFLAGS = -std=c++11

libevents.a: event.o eventheaders.o event_age_carI_carY.o event_age_carY_carA.o\
	event_age_immI_immY.o event_age_immY_immA.o event_age_susI_susY.o\
	event_age_susY_susA.o event_birth.o event_death_carA.o event_death_immA.o\
	event_death_susA.o event_death_sicA.o event_death_sicI.o event_death_sicY.o\
	event_encounter.o event_external_tra_susA.o event_external_tra_susI.o\
	event_external_tra_susY.o event_tra_susA.o event_tra_susI.o event_tra_susY.o\
	event_inv_infI.o event_inv_infY.o event_inv_infA.o event_noninv_infA.o\
	event_noninv_infI.o event_noninv_infY.o event_rec_carA_immA.o\
	event_rec_carA_immPerA.o event_rec_carI.o event_rec_carY.o event_rec_sicA.o\
	event_rec_sicI.o event_rec_sicY.o event_tra_immI.o event_tra_immY.o\
	event_tra_immA.o event_external_tra_immI.o event_external_tra_immY.o\
	event_external_tra_immA.o event_rec_immI.o event_rec_immY.o event_rec_immA.o
	ar rcs $@ $^

.PHONY: all clean install

clean:
	rm -f *.o libevents.a

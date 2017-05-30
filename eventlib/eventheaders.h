#include "event.h"
#include "event_age_carI_carY.h"
#include "event_age_carY_carA.h"
#include "event_age_immI_immY.h"
#include "event_age_immY_immA.h"
#include "event_age_susI_susY.h"
#include "event_age_susY_susA.h"
#include "event_birth.h"
#include "event_death_carA.h"
#include "event_death_immA.h"
#include "event_death_susA.h"
#include "event_death_sicA.h"
#include "event_death_sicI.h"
#include "event_death_sicY.h"
#include "event_encounter.h"
#include "event_external_tra_susA.h"
#include "event_external_tra_susI.h"
#include "event_external_tra_susY.h"
#include "event_external_tra_immI.h"
#include "event_external_tra_immY.h"
#include "event_external_tra_immA.h"
#include "event_tra_susA.h"
#include "event_tra_susI.h"
#include "event_tra_susY.h"
#include "event_tra_immI.h"
#include "event_tra_immY.h"
#include "event_tra_immA.h"
#include "event_inv_infA.h"
#include "event_inv_infI.h"
#include "event_inv_infY.h"
#include "event_noninv_infA.h"
#include "event_noninv_infI.h"
#include "event_noninv_infY.h"
#include "event_rec_carA_imm.h"
#include "event_rec_carA_noImm.h"
#include "event_rec_carA_immPerA.h"
#include "event_rec_carI_imm.h"
#include "event_rec_carI_noImm.h"
#include "event_rec_carY_imm.h"
#include "event_rec_carY_noImm.h"
#include "event_rec_sicA.h"
#include "event_rec_sicI.h"
#include "event_rec_sicY.h"

#include "event_rec_immI.h"
#include "event_rec_immY.h"
#include "event_rec_immA.h"

#include "event_inv_infA_seasonal.h"
#include "event_inv_infI_seasonal.h"
#include "event_inv_infY_seasonal.h"
#include "event_noninv_infA_seasonal.h"
#include "event_noninv_infI_seasonal.h"
#include "event_noninv_infY_seasonal.h"

#include "eventI_age_carI_carY.h"
#include "eventI_age_carY_carA.h"
#include "eventI_death_carA.h"
#include "eventI_death_sicA.h"
#include "eventI_death_sicI.h"
#include "eventI_death_sicY.h"
#include "eventI_external_tra_susA.h"
#include "eventI_external_tra_susI.h"
#include "eventI_external_tra_susY.h"
#include "eventI_external_tra_immI.h"
#include "eventI_external_tra_immY.h"
#include "eventI_external_tra_immA.h"
#include "eventI_tra_susA.h"
#include "eventI_tra_susI.h"
#include "eventI_tra_susY.h"
#include "eventI_tra_immI.h"
#include "eventI_tra_immY.h"
#include "eventI_tra_immA.h"
#include "eventI_inv_infA.h"
#include "eventI_inv_infI.h"
#include "eventI_inv_infY.h"
#include "eventI_noninv_infA.h"
#include "eventI_noninv_infI.h"
#include "eventI_noninv_infY.h"
#include "eventI_rec_carA_imm.h"
#include "eventI_rec_carA_noImm.h"
#include "eventI_rec_carA_immPerA.h"
#include "eventI_rec_carI_imm.h"
#include "eventI_rec_carI_noImm.h"
#include "eventI_rec_carY_imm.h"
#include "eventI_rec_carY_noImm.h"
#include "eventI_rec_sicA.h"
#include "eventI_rec_sicI.h"
#include "eventI_rec_sicY.h"

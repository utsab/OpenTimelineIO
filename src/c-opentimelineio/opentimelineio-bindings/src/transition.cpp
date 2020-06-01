#include "copentimelineio/transition.h"
#include <opentime/rationalTime.h>
#include <opentime/timeRange.h>
#include <opentimelineio/anyDictionary.h>
#include <opentimelineio/errorStatus.h>
#include <opentimelineio/transition.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif
    const char* TransitionType_SMPTE_Dissolve =
        OTIO_NS::Transition::Type::SMPTE_Dissolve;
    const char* TransitionType_Custom = OTIO_NS::Transition::Type::Custom;

    Transition* Transition_create(
        const char*    name,
        const char*    transition_type,
        RationalTime*  in_offset,
        RationalTime*  out_offset,
        AnyDictionary* metadata)
    {
        return reinterpret_cast<Transition*>(new OTIO_NS::Transition(
            name,
            transition_type,
            *reinterpret_cast<OTIO_NS::RationalTime*>(in_offset),
            *reinterpret_cast<OTIO_NS::RationalTime*>(out_offset),
            *reinterpret_cast<OTIO_NS::AnyDictionary*>(metadata)));
    }
    _Bool Transition_overlapping(Transition* self)
    {
        return reinterpret_cast<OTIO_NS::Transition*>(self)->overlapping();
    }
    const char* Transition_transition_type(Transition* self)
    {
        std::string returnStr =
            reinterpret_cast<OTIO_NS::Transition*>(self)->transition_type();
        char* charPtr = (char*) malloc((returnStr.size() + 1) * sizeof(char));
        strcpy(charPtr, returnStr.c_str());
        return charPtr;
    }
    void Transition_set_transition_type(
        Transition* self, const char* transition_type)
    {
        reinterpret_cast<OTIO_NS::Transition*>(self)->set_transition_type(
            transition_type);
    }
    RationalTime* Transition_in_offset(Transition* self)
    {
        opentime::RationalTime rationalTime =
            reinterpret_cast<OTIO_NS::Transition*>(self)->in_offset();
        return reinterpret_cast<RationalTime*>(
            new opentime::RationalTime(rationalTime));
    }
    void Transition_set_in_offset(Transition* self, RationalTime* in_offset)
    {
        reinterpret_cast<OTIO_NS::Transition*>(self)->set_in_offset(
            *reinterpret_cast<OTIO_NS::RationalTime*>(in_offset));
    }
    RationalTime* Transition_out_offset(Transition* self)
    {
        opentime::RationalTime rationalTime =
            reinterpret_cast<OTIO_NS::Transition*>(self)->out_offset();
        return reinterpret_cast<RationalTime*>(
            new opentime::RationalTime(rationalTime));
    }
    void Transition_set_out_offset(Transition* self, RationalTime* out_offset)
    {
        reinterpret_cast<OTIO_NS::Transition*>(self)->set_out_offset(
            *reinterpret_cast<OTIO_NS::RationalTime*>(out_offset));
    }
    RationalTime*
    Transition_duration(Transition* self, OTIOErrorStatus* error_status)
    {
        opentime::RationalTime rationalTime =
            reinterpret_cast<OTIO_NS::Transition*>(self)->duration(
                reinterpret_cast<OTIO_NS::ErrorStatus*>(error_status));
        return reinterpret_cast<RationalTime*>(
            new opentime::RationalTime(rationalTime));
    }
    TimeRange*
    Transition_range_in_parent(Transition* self, OTIOErrorStatus* error_status)
    {
        nonstd::optional<opentime::TimeRange> timeRangeOptional =
            reinterpret_cast<OTIO_NS::Transition*>(self)->range_in_parent(
                reinterpret_cast<OTIO_NS::ErrorStatus*>(error_status));
        if(timeRangeOptional == nonstd::nullopt) return NULL;
        return reinterpret_cast<TimeRange*>(
            new opentime::TimeRange(timeRangeOptional.value()));
    }
    TimeRange* Transition_trimmed_range_in_parent(
        Transition* self, OTIOErrorStatus* error_status)
    {
        nonstd::optional<opentime::TimeRange> timeRangeOptional =
            reinterpret_cast<OTIO_NS::Transition*>(self)
                ->trimmed_range_in_parent(
                    reinterpret_cast<OTIO_NS::ErrorStatus*>(error_status));
        if(timeRangeOptional == nonstd::nullopt) return NULL;
        return reinterpret_cast<TimeRange*>(
            new opentime::TimeRange(timeRangeOptional.value()));
    }
#ifdef __cplusplus
}
#endif
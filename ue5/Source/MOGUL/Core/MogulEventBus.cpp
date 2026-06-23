// MOGUL (Project ATLAS) — Event Bus implementation.
#include "Core/MogulEventBus.h"
#include "MogulLog.h"

void UMogulEventBus::Emit(FName EventId, const FString& Payload)
{
	UE_LOG(LogMogul, Verbose, TEXT("[Event] %s : %s"), *EventId.ToString(), *Payload);
	OnEvent.Broadcast(EventId, Payload);
}

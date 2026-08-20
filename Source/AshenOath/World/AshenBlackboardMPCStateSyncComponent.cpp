// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenBlackboardMPCStateSyncComponent.h"

UAshenBlackboardMPCStateSyncComponent::UAshenBlackboardMPCStateSyncComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBlackboardMPCStateSyncComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackboardMPCStateSyncComponent: Pushed Corruption (%.2f) and Resolve (%.2f) to global MPC"),
		NewState.Corruption, NewState.Resolve);
}

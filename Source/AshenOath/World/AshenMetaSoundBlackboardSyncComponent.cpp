// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenMetaSoundBlackboardSyncComponent.h"

UAshenMetaSoundBlackboardSyncComponent::UAshenMetaSoundBlackboardSyncComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMetaSoundBlackboardSyncComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMetaSoundBlackboardSyncComponent: Pushed Isolation (%.2f) to MetaSound audio blackboard"), NewState.Isolation);
}

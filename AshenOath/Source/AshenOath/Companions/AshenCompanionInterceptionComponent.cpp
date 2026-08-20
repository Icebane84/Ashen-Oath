// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 542: Ashen Companion Interception Component

#include "AshenCompanionInterceptionComponent.h"

UAshenCompanionInterceptionComponent::UAshenCompanionInterceptionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bInterceptionActive = false;
}

bool UAshenCompanionInterceptionComponent::TriggerPreemptiveInterception(FName InterceptorID, FVector TargetDangerPoint)
{
	if (InterceptorID.IsNone()) return false;

	bInterceptionActive = true;
	const FVector InterceptPoint = TargetDangerPoint + FVector(100, 0, 0);

	OnInterceptionTriggered.Broadcast(InterceptorID, InterceptPoint);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionInterceptionComponent: PRE-EMPTIVE INTERCEPTION TRIGGERED -> Companion '%s' intercepting at (%s)."),
		*InterceptorID.ToString(), *InterceptPoint.ToString());

	return true;
}

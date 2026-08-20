// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 793: Ashen Oathbringer Weapon Annotation Broadcaster

#include "AshenOathbringerWeaponAnnotationBroadcaster.h"

void UAshenOathbringerWeaponAnnotationBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAnnotationsBroadcasted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerWeaponAnnotationBroadcaster: Initialized — Oathbringer Weapon Annotation Broadcaster ONLINE."));
}

void UAshenOathbringerWeaponAnnotationBroadcaster::BroadcastWeaponAnnotation(FText AnnotationText, FName UpgradeTag)
{
	TotalAnnotationsBroadcasted++;
	OnAnnotationBroadcasted.Broadcast(AnnotationText, UpgradeTag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerWeaponAnnotationBroadcaster: WEAPON ANNOTATION BROADCASTED -> Text: '%s' | Tag: '%s' (Total: %d)."),
		*AnnotationText.ToString(), *UpgradeTag.ToString(), TotalAnnotationsBroadcasted);
}

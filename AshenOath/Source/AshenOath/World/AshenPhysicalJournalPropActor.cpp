// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenPhysicalJournalPropActor.h"

AAshenPhysicalJournalPropActor::AAshenPhysicalJournalPropActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenPhysicalJournalPropActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenPhysicalJournalPropActor: Physical Journal Prop initialized at campfire."));
}

void AAshenPhysicalJournalPropActor::OpenJournalProp()
{
	bIsJournalOpen = true;
	if (OnJournalPropOpened.IsBound())
	{
		OnJournalPropOpened.Broadcast();
	}
	UE_LOG(LogTemp, Log, TEXT("AAshenPhysicalJournalPropActor: Journal opened in 3D world space."));
}

void AAshenPhysicalJournalPropActor::CloseJournalProp()
{
	bIsJournalOpen = false;
	UE_LOG(LogTemp, Log, TEXT("AAshenPhysicalJournalPropActor: Journal closed in 3D world space."));
}

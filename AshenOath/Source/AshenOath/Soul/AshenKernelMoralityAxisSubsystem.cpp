// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenKernelMoralityAxisSubsystem.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Engine/GameInstance.h"

void UAshenKernelMoralityAxisSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	if (GI)
	{
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			Kernel->OnStateVectorInvalidated.AddDynamic(this, &UAshenKernelMoralityAxisSubsystem::OnSoulStateVectorInvalidated);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenKernelMoralityAxisSubsystem: Non-binary morality axis subsystem subscribed to Soul Constellation Kernel."));
}

void UAshenKernelMoralityAxisSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenKernelMoralityAxisSubsystem::OnSoulStateVectorInvalidated(const FSoulStateVector& NewStateVector)
{
	CompassionAxis = NewStateVector.SerafinaTrust;
	PragmatismAxis = NewStateVector.GarrettTrust;
	CourageAxis    = NewStateVector.Resolve;
	UE_LOG(LogTemp, Log, TEXT("UAshenKernelMoralityAxisSubsystem: Morality axes updated — Compassion=%f Pragmatism=%f Courage=%f"),
		CompassionAxis, PragmatismAxis, CourageAxis);
}

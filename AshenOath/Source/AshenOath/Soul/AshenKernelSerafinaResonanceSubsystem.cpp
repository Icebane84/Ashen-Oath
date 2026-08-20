// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenKernelSerafinaResonanceSubsystem.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Engine/GameInstance.h"

void UAshenKernelSerafinaResonanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	if (GI)
	{
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			Kernel->OnStateVectorInvalidated.AddDynamic(this, &UAshenKernelSerafinaResonanceSubsystem::OnSoulStateVectorInvalidated);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenKernelSerafinaResonanceSubsystem: Subscribed to Soul Constellation Kernel for Serafina resonance."));
}

void UAshenKernelSerafinaResonanceSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenKernelSerafinaResonanceSubsystem::OnSoulStateVectorInvalidated(const FSoulStateVector& NewStateVector)
{
	SerafinaResonanceScore = NewStateVector.SerafinaTrust;
	bSupportSpellsAvailable = (NewStateVector.SerafinaTrust > 0.3f);
	UE_LOG(LogTemp, Log, TEXT("UAshenKernelSerafinaResonanceSubsystem: Serafina resonance updated — Score=%f, SupportSpells=%s"),
		SerafinaResonanceScore, bSupportSpellsAvailable ? TEXT("AVAILABLE") : TEXT("DISABLED"));
}

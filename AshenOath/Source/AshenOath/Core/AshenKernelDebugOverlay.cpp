// AshenKernelDebugOverlay.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenKernelDebugOverlay.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenOath_DirectorSubsystem.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "GameFramework/Pawn.h"

void UAshenKernelDebugOverlay::NativeConstruct()
{
	Super::NativeConstruct();
}

void UAshenKernelDebugOverlay::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!bShowOverlay || !GEngine) return;

	UGameInstance* GI = GetGameInstance();
	if (!GI) return;

	UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>();
	if (!Kernel) return;

	const FSoulStateVector& State = Kernel->GetStateVector();
	const FBehavioralProfile& Profile = Kernel->GetActiveProfile();

	float Debt = State.IntegrationDebt;
	FString StageStr;
	switch (State.GetDebtStage())
	{
	case EIntegrationDebtStage::Dormant: StageStr = TEXT("DORMANT (0-49%)"); break;
	case EIntegrationDebtStage::MemoryBleed: StageStr = TEXT("MEMORY BLEED (50-74%)"); break;
	case EIntegrationDebtStage::RuntimeNoise: StageStr = TEXT("RUNTIME NOISE (75-99%)"); break;
	case EIntegrationDebtStage::ForcedCollapse: StageStr = TEXT("FORCED COLLAPSE (100%)"); break;
	}

	FString LensStr;
	switch (State.PrimaryLens)
	{
	case EInterpretiveLens::Accountability: LensStr = TEXT("Accountability"); break;
	case EInterpretiveLens::Grace: LensStr = TEXT("Grace"); break;
	case EInterpretiveLens::Utility: LensStr = TEXT("Utility"); break;
	}

	int32 ImprintCount = 0;
	float Embers = 0.0f;
	float Ash = 0.0f;

	if (UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>())
	{
		if (APawn* Player = Director->GetPlayerPawn())
		{
			if (UAshenOath_ImprintBufferComponent* Buffer = Player->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
			{
				ImprintCount = Buffer->GetImprintCount();
			}
			if (UAshenOath_CurrencyComponent* Currency = Player->FindComponentByClass<UAshenOath_CurrencyComponent>())
			{
				Embers = Currency->GetEmbers();
				Ash = Currency->GetAsh();
			}
		}
	}

	FString DebugMessage = FString::Printf(
		TEXT("[ASHEN OATH KERNEL DEBUG]\n")
		TEXT("Lens: %s | Debt: %.1f%% [%s]\n")
		TEXT("Resolve: %.2f | Corruption: %.2f | Isolation: %.2f\n")
		TEXT("GarrettTrust: %.2f | SerafinaTrust: %.2f | Despair: %.2f\n")
		TEXT("Profile -> Stance:%d Empathic:%d Tactical:%d\n")
		TEXT("Imprints Buffered: %d | Embers: %.0f | Ash: %.0f"),
		*LensStr, Debt * 100.0f, *StageStr,
		State.Resolve, State.Corruption, State.Isolation,
		State.GarrettTrust, State.SerafinaTrust, Kernel->GetDespairLevel(),
		static_cast<int32>(Profile.Stance), static_cast<int32>(Profile.Empathic), static_cast<int32>(Profile.Tactical),
		ImprintCount, Embers, Ash
	);

	GEngine->AddOnScreenDebugMessage(999, 0.1f, FColor::Cyan, DebugMessage);
}


void UAshenKernelDebugOverlay::ToggleDebugOverlay()
{
	bShowOverlay = !bShowOverlay;
}

FText UAshenKernelDebugOverlay::FormatKernelDebugText() const
{
	return FText::FromString("Kernel Debug Overlay Active");
}

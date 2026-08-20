// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenVerticalSliceDiagHUD.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_ManaComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenCompanionAIComponent.h"
#include "AshenTraumaMatrixComponent.h"
#include "AshenWhisperingWindSubsystem.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "AbilitySystemComponent.h"

AAshenVerticalSliceDiagHUD::AAshenVerticalSliceDiagHUD()
{
	bEnabled = false;
}

void AAshenVerticalSliceDiagHUD::AshenDiagHUD(int32 EnableValue)
{
	bEnabled = (EnableValue != 0);
	UE_LOG(LogTemp, Log, TEXT("AAshenVerticalSliceDiagHUD: %s"), bEnabled ? TEXT("ENABLED") : TEXT("DISABLED"));
}

void AAshenVerticalSliceDiagHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!bEnabled || !Canvas) return;

	APawn* Player = GetOwningPawn();
	if (!Player) return;

	float Y = 40.0f;
	const float X = 24.0f;
	const float BarWidth = 160.0f;
	const float BarH = 10.0f;

	// ----------------------------------------------------------------
	// ROW 1 — Core Resources
	// ----------------------------------------------------------------
	DrawText(TEXT("=== ASHEN OATH DIAG HUD ==="), FLinearColor::Yellow, X, Y, nullptr, 1.0f, false);
	Y += 20.0f;

	if (UAshenOath_HealthComponent* Health = Player->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		float Frac = Health->GetMaxHealth() > 0.f ? Health->GetCurrentHealth() / Health->GetMaxHealth() : 0.f;
		DrawRow(TEXT("HP"), FString::Printf(TEXT("%.0f / %.0f"), Health->GetCurrentHealth(), Health->GetMaxHealth()), Y, FLinearColor::Red);
		DrawProgressBar(X + 140.f, Y - 14.f, BarWidth, BarH, Frac, FLinearColor::Red);
		Y += 4.f;
	}

	if (UAshenOath_StaminaComponent* Stamina = Player->FindComponentByClass<UAshenOath_StaminaComponent>())
	{
		float Frac = Stamina->GetMaxStamina() > 0.f ? Stamina->GetCurrentStamina() / Stamina->GetMaxStamina() : 0.f;
		DrawRow(TEXT("ST"), FString::Printf(TEXT("%.0f / %.0f"), Stamina->GetCurrentStamina(), Stamina->GetMaxStamina()), Y, FLinearColor::Green);
		DrawProgressBar(X + 140.f, Y - 14.f, BarWidth, BarH, Frac, FLinearColor::Green);
		Y += 4.f;
	}

	if (UAshenOath_SanityComponent* Sanity = Player->FindComponentByClass<UAshenOath_SanityComponent>())
	{
		float Frac = Sanity->GetMaxSanity() > 0.f ? Sanity->GetCurrentSanity() / Sanity->GetMaxSanity() : 0.f;
		DrawRow(TEXT("SN"), FString::Printf(TEXT("%.0f / %.0f"), Sanity->GetCurrentSanity(), Sanity->GetMaxSanity()), Y, FLinearColor(0.6f, 0.3f, 1.0f));
		DrawProgressBar(X + 140.f, Y - 14.f, BarWidth, BarH, Frac, FLinearColor(0.6f, 0.3f, 1.0f));
		Y += 4.f;
	}

	// ----------------------------------------------------------------
	// ROW 2 — Corruption + Whispering Wind
	// ----------------------------------------------------------------
	Y += 8.f;
	DrawText(TEXT("--- CORRUPTION / AUDIO ---"), FLinearColor(0.5f, 0.5f, 0.5f), X, Y, nullptr, 0.85f, false);
	Y += 16.f;

	if (UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr)
	{
		if (UAshenWhisperingWindSubsystem* Whispers = GI->GetSubsystem<UAshenWhisperingWindSubsystem>())
		{
			DrawRow(TEXT("Whisper Intensity"), FString::Printf(TEXT("%.2f"), Whispers->GetWhisperIntensity()), Y, FLinearColor(0.8f, 0.4f, 0.0f));
			DrawProgressBar(X + 200.f, Y - 14.f, BarWidth, BarH, Whispers->GetWhisperIntensity(), FLinearColor(0.8f, 0.4f, 0.0f));
			Y += 4.f;
			DrawRow(TEXT("Whisper Volume"),    FString::Printf(TEXT("%.2f"), Whispers->GetWhisperVolume()), Y, FLinearColor(0.9f, 0.6f, 0.1f));
		}
	}

	// ----------------------------------------------------------------
	// ROW 3 — Companion AI State
	// ----------------------------------------------------------------
	Y += 16.f;
	DrawText(TEXT("--- COMPANION AI ---"), FLinearColor(0.5f, 0.5f, 0.5f), X, Y, nullptr, 0.85f, false);
	Y += 16.f;

	TArray<AActor*> Companions;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), Companions);
	for (AActor* Actor : Companions)
	{
		if (UAshenCompanionAIComponent* AI = Actor->FindComponentByClass<UAshenCompanionAIComponent>())
		{
			FString StateName = GetCompanionStateName(static_cast<uint8>(AI->CurrentAIState));
			DrawRow(Actor->GetName().Left(14), StateName, Y, FLinearColor(0.0f, 1.0f, 1.0f));
			break; // Only first companion for HUD brevity
		}
	}

	// ----------------------------------------------------------------
	// ROW 4 — Nearby Enemy Trauma Matrix
	// ----------------------------------------------------------------
	Y += 16.f;
	DrawText(TEXT("--- TRAUMA MATRIX ---"), FLinearColor(0.5f, 0.5f, 0.5f), X, Y, nullptr, 0.85f, false);
	Y += 16.f;

	TArray<AActor*> Enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), Enemies);
	for (AActor* Actor : Enemies)
	{
		if (UAshenTraumaMatrixComponent* TM = Actor->FindComponentByClass<UAshenTraumaMatrixComponent>())
		{
			DrawRow(TEXT("Target"),   UEnum::GetValueAsString(TM->TargetVector), Y, FLinearColor::Red);
			DrawRow(TEXT("Argument"), TM->AdversarialArgument.Left(32), Y, FLinearColor(1.0f, 0.4f, 0.4f));
			DrawRow(TEXT("Disruption x"), FString::Printf(TEXT("%.2f"), TM->DisruptionMultiplier), Y, FLinearColor(1.0f, 0.6f, 0.6f));
			break;
		}
	}

	// ----------------------------------------------------------------
	// ROW 5 — GAS Active Tags
	// ----------------------------------------------------------------
	Y += 8.f;
	DrawText(TEXT("--- ACTIVE GAS TAGS ---"), FLinearColor(0.5f, 0.5f, 0.5f), X, Y, nullptr, 0.85f, false);
	Y += 16.f;

	if (UAbilitySystemComponent* ASC = Player->FindComponentByClass<UAbilitySystemComponent>())
	{
		FGameplayTagContainer GasTags;
		ASC->GetOwnedGameplayTags(GasTags);
		for (const FGameplayTag& Tag : GasTags)
		{
			DrawRow(TEXT("TAG"), Tag.ToString(), Y, FLinearColor(0.4f, 1.0f, 0.4f));
			if (Y > Canvas.Get()->ClipY - 40.f) break; // Prevent overflow
		}
	}
}

void AAshenVerticalSliceDiagHUD::DrawRow(const FString& Label, const FString& Value, float& YOffset, FLinearColor Color)
{
	if (!Canvas) return;
	const FString Line = FString::Printf(TEXT("%-20s %s"), *Label, *Value);
	DrawText(Line, Color, 24.f, YOffset, nullptr, 0.85f, false);
	YOffset += 16.f;
}

void AAshenVerticalSliceDiagHUD::DrawProgressBar(float X, float Y, float Width, float Height, float Fraction, FLinearColor BarColor)
{
	if (!Canvas) return;
	Fraction = FMath::Clamp(Fraction, 0.f, 1.f);

	// Background track
	DrawRect(FLinearColor(0.15f, 0.15f, 0.15f, 0.8f), X, Y, Width, Height);

	// Filled portion
	if (Fraction > 0.f)
	{
		DrawRect(BarColor.CopyWithNewOpacity(0.85f), X, Y, Width * Fraction, Height);
	}
}

FString AAshenVerticalSliceDiagHUD::GetCompanionStateName(uint8 State) const
{
	switch (State)
	{
	case 0: return TEXT("OffensiveSupport");
	case 1: return TEXT("TacticalTriage");
	case 2: return TEXT("UnchainedContainment");
	case 3: return TEXT("RecoveryAnchoring");
	default: return TEXT("Unknown");
	}
}

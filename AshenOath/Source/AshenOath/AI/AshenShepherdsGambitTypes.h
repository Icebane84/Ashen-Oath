// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenShepherdsGambitTypes.generated.h"

UENUM(BlueprintType)
enum class EContainmentState : uint8
{
	StandardCooperation UMETA(DisplayName = "Standard Cooperation (Three-Legged Stool)"),
	ContainmentActive   UMETA(DisplayName = "Containment Active (The Shepherd's Gambit)"),
	BulwarkLockout      UMETA(DisplayName = "Bulwark Lockout (Serafina Burnout >= 0.7)"),
	ContainmentResolved UMETA(DisplayName = "Containment Resolved (Humanity Restored)")
};

UENUM(BlueprintType)
enum class EUnchainedHazardLevel : uint8
{
	Safe        UMETA(DisplayName = "Safe (C < 0.7)"),
	Hazardous   UMETA(DisplayName = "Hazardous (0.7 <= C < 0.9)"),
	Catastrophic UMETA(DisplayName = "Catastrophic (C >= 0.9 / Target-Blind)")
};

USTRUCT(BlueprintType)
struct FCompanionContainmentBehavior
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Containment")
	EContainmentState CurrentState = EContainmentState::StandardCooperation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Containment")
	bool bIsProtectingCaster = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Containment")
	float ActiveDampenerDuration = 0.0f;
};

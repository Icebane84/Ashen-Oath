// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionFormationComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenFormationRole : uint8
{
	VanguardFront    UMETA(DisplayName = "Vanguard Front"),
	FlankSupport     UMETA(DisplayName = "Flank Support"),
	RearGuard        UMETA(DisplayName = "Rear Guard")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFormationOffsetUpdatedSignature, EAshenFormationRole, Role, FVector, TargetLocation);

/**
 * UAshenCompanionFormationComponent
 *
 * Calculates dynamic tactical formation offsets for companion AI pawns (Garrett, Serafina)
 * positioned around Kaelen during exploration and combat encounters.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFormationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionFormationComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Formation")
	FVector CalculateFormationOffset(EAshenFormationRole Role, FVector PlayerLocation, FVector PlayerForwardVector);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Formation")
	EAshenFormationRole AssignedRole = EAshenFormationRole::FlankSupport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Formation")
	float FormationDistance = 250.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Formation|Events")
	FOnFormationOffsetUpdatedSignature OnFormationOffsetUpdated;
};

// AshenCompanionBarkComponent.h
// Copyright Ashen Oath. All rights reserved.
// Contextual companion voice bark component for Garrett and Serafina.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVector.h"
#include "AshenCompanionBarkComponent.generated.h"

UENUM(BlueprintType)
enum class ECompanionType : uint8
{
	Garrett,
	Serafina
};

/**
 * @class UAshenCompanionBarkComponent
 * @brief Contextual voice bark controller attached to Garrett and Serafina companion actors.
 * Evaluates state vector, integration debt, and low-health events to trigger voice barks.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionBarkComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionBarkComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Companion identity (Garrett or Serafina). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Companion")
	ECompanionType CompanionType;

	/** Minimum cooldown between voice barks in seconds. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Companion")
	float BarkCooldownSeconds;

	/** Triggers a voice bark with a specified line. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	void SpeakBarkLine(const FString& Line);

	/** Callback when Soul Constellation Kernel publishes a new state vector. */
	UFUNCTION()
	void HandleStateVectorInvalidated(const FSoulStateVector& NewState);

	/** Callback when player health drops low or dies. */
	UFUNCTION()
	void HandleCombatEventFired(FString EventType, AActor* Instigator, AActor* Target, float Magnitude);


private:
	FTimerHandle BarkCooldownTimerHandle;
	bool bCanSpeak;
	EIntegrationDebtStage LastDebtStage;
};

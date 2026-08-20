// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanityBreakEventsComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenSanityBreakType : uint8
{
	ParalyticTerror     UMETA(DisplayName = "Paralytic Terror (Stun / Freeze)"),
	ViolentFrenzy       UMETA(DisplayName = "Violent Frenzy (Uncontrolled Attacks)"),
	HallucinatoryWave   UMETA(DisplayName = "Hallucinatory Phantom Wave")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityBreakEventTriggeredSignature, EAshenSanityBreakType, BreakType, float, Duration);

/**
 * UAshenSanityBreakEventsComponent
 *
 * Component evaluating acute Sanity drops (<15%) to trigger immediate psychological break events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityBreakEventsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityBreakEventsComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanityBreak")
	void EvaluateSanityForBreak(float CurrentSanity, float MaxSanity);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityBreak")
	float SanityBreakThreshold = 15.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanityBreak|Events")
	FOnSanityBreakEventTriggeredSignature OnSanityBreakTriggered;

private:
	bool bBreakActive = false;
};

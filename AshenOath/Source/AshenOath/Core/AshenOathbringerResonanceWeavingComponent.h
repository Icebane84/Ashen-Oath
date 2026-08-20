// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerResonanceWeavingComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenFinisherResonance : uint8
{
	RadiantFlameFinisher UMETA(DisplayName = "Radiant Flame (Holy Burst / Heal)"),
	AshenVoidFinisher    UMETA(DisplayName = "Ashen Void (Shadow Slice / Life Leech)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResonanceFinisherExecutedSignature, EAshenFinisherResonance, FinisherType, float, BonusDamage);

/**
 * UAshenOathbringerResonanceWeavingComponent
 *
 * Moment-of-execution combo finisher modifier allowing Kaelen to weave Light or Shadow resonance into finishers.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerResonanceWeavingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerResonanceWeavingComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonanceWeaving")
	void ExecuteResonanceFinisher(EAshenFinisherResonance FinisherType, AActor* TargetActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonanceWeaving|Events")
	FOnResonanceFinisherExecutedSignature OnResonanceFinisherExecuted;
};

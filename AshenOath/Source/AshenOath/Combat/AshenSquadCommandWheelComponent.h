// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCompanionTacticalOrderAbility.h"
#include "AshenSquadCommandWheelComponent.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTacticalCommandWheelToggled, bool, bIsOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionTacticalOrderDispatched, EAshenSquadCommand, Command, bool, bWasFallback);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnCompanionTacticalOrderNative, EAshenSquadCommand, bool);

/**
 * UAshenSquadCommandWheelComponent
 *
 * In-combat radial companion command wheel.
 * Manages decoupled 0.20x bullet-time dilation and multi-dimensional
 * relational matrix gating via FRelationalMatrix_V2.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSquadCommandWheelComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSquadCommandWheelComponent();

	virtual void BeginPlay() override;

	/** Opens the command wheel and engages 0.20x global time dilation */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Tactical")
	void OpenCommandWheel();

	/** Closes the command wheel and restores 1.0x global time dilation */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Tactical")
	void CloseCommandWheel();

	/** Evaluates relational matrix predicates and executes companion squad command */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Tactical")
	bool ExecuteSquadCommand(EAshenSquadCommand DesiredCommand, AActor* TargetActor);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Tactical")
	bool IsCommandWheelOpen() const { return bIsWheelOpen; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Tactical")
	float GetBulletTimeDilation() const { return BulletTimeDilation; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Tactical")
	FOnTacticalCommandWheelToggled OnCommandWheelStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Tactical")
	FOnCompanionTacticalOrderDispatched OnSquadOrderDispatched;

	/** Native C++ delegate supporting lambdas */
	FOnCompanionTacticalOrderNative OnSquadOrderDispatchedNative;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Tactical", meta = (ClampMin = "0.05", ClampMax = "1.0"))
	float BulletTimeDilation = 0.20f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Tactical")
	bool bIsWheelOpen = false;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};

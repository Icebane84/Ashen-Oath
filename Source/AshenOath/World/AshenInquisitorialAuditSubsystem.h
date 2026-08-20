// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenInquisitorialAuditSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInquisitorialSuspicionEscalatedSignature, float, CurrentSuspicionLevel, bool, bPurgeOrderActive);

/**
 * UAshenInquisitorialAuditSubsystem
 *
 * World Subsystem auditing Elder Valerius's inquisitorial suspicion levels against the trio.
 */
UCLASS()
class ASHENOATH_API UAshenInquisitorialAuditSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Inquisitorial")
	void EscalateInquisitorialSuspicion(float Delta);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Inquisitorial|Events")
	FOnInquisitorialSuspicionEscalatedSignature OnSuspicionEscalated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Inquisitorial")
	float SuspicionLevel = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Inquisitorial")
	bool bPurgeOrderActive = false;
};

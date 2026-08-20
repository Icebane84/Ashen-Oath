// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenConcealmentComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConcealmentStateChangedSignature, bool, bConcealed);

/**
 * UAshenConcealmentComponent
 *
 * Garrett's smoke balm concealment and threat reset component.
 * Grants temporary invisibility / threat-dropped status to Kaelen or party members
 * standing inside alchemical smoke balm zones.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConcealmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenConcealmentComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stealth")
	void EnterConcealment(float Duration = 5.0f);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stealth")
	void ExitConcealment();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Stealth")
	bool bIsConcealed = false;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stealth|Events")
	FOnConcealmentStateChangedSignature OnConcealmentStateChanged;

private:
	FTimerHandle ConcealmentTimerHandle;
};

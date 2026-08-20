// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenOathbringerGreatswordActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerAegisReflectedSignature, float, ReflectedDamage, FName, ReflectedElementType);

/**
 * AAshenOathbringerGreatswordActor
 *
 * Weapon Actor for Kaelen's two-handed Oathbringer greatsword with diegetic wear & Aegis Reflection.
 */
UCLASS()
class ASHENOATH_API AAshenOathbringerGreatswordActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOathbringerGreatswordActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oathbringer")
	void ReflectAegisEnergy(float IncomingDamage, FName ElementType);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Oathbringer|Events")
	FOnOathbringerAegisReflectedSignature OnAegisReflected;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Oathbringer")
	bool bIsResonanceTuned = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Oathbringer")
	float BaseWeaponDamage = 150.0f;
};

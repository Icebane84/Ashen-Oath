// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSanctuaryField.generated.h"

class USphereComponent;

/**
 * AAshenSanctuaryField
 * Physical sanctuary field spawned dynamically by Serafina's Sacred Barrier.
 * Overlap volume grants +250% stamina regeneration and AoE damage nullification.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryField : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryField();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Sanctuary")
	USphereComponent* FieldSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float StaminaAccelerationMultiplier = 3.5f; // +250% acceleration

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float FieldRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float LifetimeSeconds = 12.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Sanctuary")
	TArray<AActor*> OverlappingAllies;

	UFUNCTION()
	void OnFieldBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnFieldEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	bool IsActorProtectedBySanctuary(const AActor* ActorToCheck) const;
};

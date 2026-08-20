// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenEmpathicNovaThrust.generated.h"

/**
 * UGA_KaelenEmpathicNovaThrust
 * Kaelen's side of the cooperative Empathic Conduit Nova finisher.
 * Handles high-velocity lunge (1400 uu/s), socket snapping (hand_l -> Staff_Thrust_Socket), and spine thrust.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenEmpathicNovaThrust : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UGA_KaelenEmpathicNovaThrust();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Movement")
	float LungeSpeed = 1400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Movement")
	float LockDistanceThreshold = 150.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Sockets")
	FName KaelenHandSocketName = TEXT("hand_l");

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Sockets")
	FName StaffSocketName = TEXT("Staff_Thrust_Socket");

	UFUNCTION(BlueprintCallable, Category = "Ashen | Finisher | Execution")
	bool ExecuteNovaThrustAndSocketLock(AActor* KaelenActor, AActor* SerafinaActor, AActor* TargetEnemy);
};

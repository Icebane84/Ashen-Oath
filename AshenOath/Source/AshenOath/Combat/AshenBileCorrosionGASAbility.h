// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenBileCorrosionGASAbility.generated.h"

/**
 * UAshenBileCorrosionGASAbility
 * Weapon coating ability transferring dripping bile from Oathbringer's crossguard to enemy armor, shredding 30% armor for 8.0s.
 */
UCLASS()
class ASHENOATH_API UAshenBileCorrosionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenBileCorrosionGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float ArmorShredPercent = 0.30f; // -30% armor

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float CorrosionDuration = 8.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ApplyBileCorrosion(AActor* TargetActor);
};

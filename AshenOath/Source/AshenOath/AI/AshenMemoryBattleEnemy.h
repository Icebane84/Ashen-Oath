// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenMemoryBattleEnemy.generated.h"

/**
 * AAshenMemoryBattleEnemy
 * Manifested psychological echo enemy in the Mindscape arena with dynamic health scaling and trauma-reactive abilities.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryBattleEnemy : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenMemoryBattleEnemy();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory Enemy")
	float BaseHealth = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory Enemy")
	float ImprintWeightMultiplier = 1.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Enemy")
	void ScaleEnemyToImprint(float ImprintWeight);
};

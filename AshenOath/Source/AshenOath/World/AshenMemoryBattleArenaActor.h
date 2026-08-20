// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryBattleArenaActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMemoryArenaStateShifted, float, IntegrityScore);

/**
 * AAshenMemoryBattleArenaActor
 * Dynamic Mindscape arena shifting walls & floating debris based on FSoulStateVector and battle intensity.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryBattleArenaActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMemoryBattleArenaActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | World")
	FOnMemoryArenaStateShifted OnArenaStateShifted;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	float ArenaIntegrity = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ShiftArenaGeometry(float IntensityDelta);
};

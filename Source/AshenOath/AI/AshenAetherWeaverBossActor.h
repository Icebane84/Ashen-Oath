// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenAetherWeaverBossActor.generated.h"

/**
 * AAshenAetherWeaverBossActor
 * 3D Void predator boss executing continuous reality-warping phasing rhythms and temporal loops until locked by Sanctuary Anchor.
 */
UCLASS()
class ASHENOATH_API AAshenAetherWeaverBossActor : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenAetherWeaverBossActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	bool bIsCorporealLocked = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void LockIntoCorporealSpace();
};

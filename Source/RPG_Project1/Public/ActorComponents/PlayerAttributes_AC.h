// All rights reserved

#pragma once

#include "Enums/WeaponType_E.h"
#include "Structures/PlayerAttributes_F.h"
#include "Enums/ApparelKind_E.h"

#include "CoreMinimal.h"
#include "AttributesBase_AC.h"
#include "PlayerAttributes_AC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_PROJECT1_API UPlayerAttributes_AC : public UAttributesBase_AC
{
	GENERATED_BODY()

public:	
	UPlayerAttributes_AC();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void TryGetHitByEnemy_Implementation(const float& IncomingPhysicalDamage, const float& IncomingMagicalDamage) override;

protected:
	virtual void BeginPlay() override;
	
public:
	UFUNCTION(BlueprintCallable)
	float CalculateRestMultiplier();

	UFUNCTION(BlueprintCallable)
	void SetMaxHpMpSp(float RestMultiplier);

	UFUNCTION(BlueprintCallable)
	void SetCurrentHpMpSp(float Hp, float Mp, float Sp);

	UFUNCTION(BlueprintCallable)
	void SetRegen(const float& RestMultiplier);

	UFUNCTION(BlueprintCallable)
	void SetDamage_RMB(const float& RestMultiplier, const EWeaponType_E& EWeaponType_E, const float& RMB_PhysicalDamage, const float& RMB_MagicalDamage);

	UFUNCTION(BlueprintCallable)
	void SetDamage_LMB(const float& RestMultiplier, const EWeaponType_E& EWeaponType_E, const float& LMB_PhysicalDamage, const float& LMB_MagicalDamage);

	UFUNCTION(BlueprintCallable)
	void SetWholeArmour(const float& RestMultiplier, const float& TorsoArmour, const float& TorsoMRes, const EApparelKind_E& TorsoKind, const float& GlovesArmour, const float& GlovesMRes, const EApparelKind_E& GlovesKind, const float& PantsArmour, const float& PantsMRes, const EApparelKind_E& PantsKind, const float& BootsArmour, const float& BootsMRes, const EApparelKind_E& BootsKind);

	UFUNCTION(BlueprintCallable)
	void SetMaxCarryWeight(const float& RestMultiplier);
	
	///////////////////////////////////////////////////////////////////
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FPlayerAttributes_F PAttributes;

private:
	/** Sets: MaxHpMpSp, CurrentHpMpSp, Regen */
	UFUNCTION()
	void SetInitialStats();

	UFUNCTION(BlueprintCallable)
	void RecalculatePAttributesStats();

	UFUNCTION()
	void InflictDamage(const float& IncPhysicalDamage, const float& IncMagicalDamage);
};
